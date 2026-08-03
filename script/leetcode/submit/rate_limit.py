#!/usr/bin/env python
"""Cross-process scheduling for LeetCode submissions.

The AI runner may solve several problems concurrently, but all submissions
share one LeetCode account.  This module provides a process-wide queue slot
with a minimum interval and an exponential cooldown after HTTP 429/503.
"""

import fcntl
import json
import os
import threading
import time
from contextlib import contextmanager
from dataclasses import dataclass
from pathlib import Path
from typing import Iterator, Optional

RATE_LIMIT_ERROR_TYPES = {"http_429", "http_503", "http_529"}
# A request can reach LeetCode even when the client does not receive a final
# response.  Continuing with the next queue item in that case may duplicate a
# submission and turn one transient network fault into a burst of requests.
UNCERTAIN_SUBMISSION_ERROR_TYPES = {
    "network_error",
    "poll_timeout",
    "submit_response_missing_id",
    "unexpected_error",
}

_LOCAL = threading.local()


def _interval_seconds() -> float:
    try:
        return max(0.0, float(os.getenv("AI_SOLVER_SUBMIT_INTERVAL", "6")))
    except ValueError:
        return 6.0


def _backoff_base_seconds() -> float:
    try:
        return max(1.0, float(os.getenv("AI_SOLVER_SUBMIT_BACKOFF_BASE", "60")))
    except ValueError:
        return 60.0


def _backoff_max_seconds() -> float:
    try:
        return max(1.0, float(os.getenv("AI_SOLVER_SUBMIT_BACKOFF_MAX", "900")))
    except ValueError:
        return 900.0


def _defer_after_seconds() -> float:
    """Avoid making a solver worker sleep through its whole 10-minute budget."""
    try:
        return max(0.0, float(os.getenv("AI_SOLVER_SUBMIT_DEFER_AFTER", "120")))
    except ValueError:
        return 120.0


def is_rate_limited_result(result: object) -> bool:
    """Return whether a typed submit result indicates remote throttling."""
    error_type = str(getattr(result, "error_type", "") or "").lower()
    status_code = getattr(result, "status_code", None)
    return error_type in RATE_LIMIT_ERROR_TYPES or status_code in {429, 503, 529}


def should_pause_submission_queue(result: object) -> bool:
    """Return whether a queue consumer should stop before the next request.

    Explicit throttling is handled by the shared exponential cooldown.  A
    transport or polling failure is also a stop condition because the server
    may have accepted the request even though the client cannot prove it.
    Deterministic verdicts such as Wrong Answer and Compile Error remain
    consumable so one bad solution does not stall unrelated queue entries.
    """
    if is_rate_limited_result(result):
        return True
    error_type = str(getattr(result, "error_type", "") or "").lower()
    return error_type in UNCERTAIN_SUBMISSION_ERROR_TYPES or (
        getattr(result, "status", "") == "Timeout"
    )


@dataclass
class SubmissionPermit:
    """The slot returned by :func:`submission_rate_limit`.

    Callers mark the permit when the server explicitly throttles a request.
    The outermost context persists the exponential cooldown atomically.
    """

    enabled: bool
    deferred: bool = False
    rate_limited: bool = False
    retry_after: Optional[float] = None

    def mark_rate_limited(self, retry_after: Optional[float] = None) -> None:
        self.rate_limited = True
        if retry_after is not None:
            try:
                self.retry_after = max(0.0, float(retry_after))
            except (TypeError, ValueError):
                pass


def _read_state(handle) -> dict:
    handle.seek(0)
    raw = handle.read().strip()
    if not raw:
        return {
            "last_submission": 0.0,
            "cooldown_until": 0.0,
            "rate_limit_streak": 0,
        }
    try:
        state = json.loads(raw)
        if isinstance(state, dict):
            return {
                "last_submission": float(state.get("last_submission", 0.0)),
                "cooldown_until": float(state.get("cooldown_until", 0.0)),
                "rate_limit_streak": max(0, int(state.get("rate_limit_streak", 0))),
            }
    except (TypeError, ValueError, json.JSONDecodeError):
        # Older runners stored only the last timestamp.  Read it once and
        # upgrade the file after this slot completes.
        try:
            return {
                "last_submission": float(raw),
                "cooldown_until": 0.0,
                "rate_limit_streak": 0,
            }
        except ValueError:
            pass
    return {
        "last_submission": 0.0,
        "cooldown_until": 0.0,
        "rate_limit_streak": 0,
    }


def _write_state(handle, state: dict) -> None:
    handle.seek(0)
    handle.truncate()
    handle.write(json.dumps(state, separators=(",", ":")))
    handle.flush()


@contextmanager
def submission_rate_limit() -> Iterator[SubmissionPermit]:
    """Serialize an account submission and apply adaptive backoff.

    The context is deliberately re-entrant in one thread because the solver's
    LeetCode gate and the submitter both protect the same HTTP call.  Nested
    callers share one permit and therefore cannot double-count a 429.
    """
    existing = getattr(_LOCAL, "permit", None)
    if existing is not None:
        yield existing
        return

    lock_name = os.getenv("AI_SOLVER_SUBMIT_LOCK")
    if not lock_name or not os.getenv("LEETCODE_COOKIE"):
        yield SubmissionPermit(enabled=False)
        return

    lock_file_path = Path(lock_name)
    lock_file_path.parent.mkdir(parents=True, exist_ok=True)
    with lock_file_path.open("a+", encoding="utf-8") as handle:
        fcntl.flock(handle.fileno(), fcntl.LOCK_EX)
        state = _read_state(handle)
        now = time.time()
        wait_seconds = max(
            state["last_submission"] + _interval_seconds() - now,
            state["cooldown_until"] - now,
            0.0,
        )
        if wait_seconds > 0:
            if wait_seconds > _defer_after_seconds():
                # The caller can finish local verification and enqueue the
                # submission instead of wasting the worker timeout asleep.
                permit = SubmissionPermit(enabled=True, deferred=True)
                _LOCAL.permit = permit
                try:
                    yield permit
                finally:
                    _LOCAL.permit = None
                    fcntl.flock(handle.fileno(), fcntl.LOCK_UN)
                return
            time.sleep(wait_seconds)
        # Reserve the slot before issuing the network request.  If a process
        # is killed mid-request, the next process still observes the interval.
        state["last_submission"] = time.time()
        _write_state(handle, state)

        permit = SubmissionPermit(enabled=True)
        _LOCAL.permit = permit
        try:
            yield permit
        finally:
            now = time.time()
            if permit.rate_limited:
                streak = state["rate_limit_streak"] + 1
                backoff = min(
                    _backoff_max_seconds(),
                    _backoff_base_seconds() * (2 ** (streak - 1)),
                )
                if permit.retry_after is not None:
                    backoff = max(backoff, permit.retry_after)
                state["rate_limit_streak"] = streak
                state["cooldown_until"] = now + backoff
            else:
                state["rate_limit_streak"] = 0
                state["cooldown_until"] = 0.0
            state["last_submission"] = now
            _write_state(handle, state)
            _LOCAL.permit = None
            fcntl.flock(handle.fileno(), fcntl.LOCK_UN)
