#!/usr/bin/env python
"""Durable, secret-free queue for deferred and uncertain submissions.

An uncertain transport result is kept in the queue but receives a short
quarantine window. That prevents the next queue invocation from immediately
duplicating a submission whose server-side outcome is unknown, while allowing
unrelated queue entries to make progress.
"""

import fcntl
import json
import os
import time
from pathlib import Path
from typing import Dict, List


def queue_path() -> Path:
    configured = os.getenv("AI_SOLVER_SUBMIT_QUEUE")
    return Path(configured or ".ai-run-logs/leetcode-submit-queue.jsonl").resolve()


def _locked_queue(path: Path):
    lock_path = path.with_name(path.name + ".lock")
    lock_path.parent.mkdir(parents=True, exist_ok=True)
    return lock_path.open("a+", encoding="utf-8")


def _read_records(path: Path) -> List[Dict]:
    if not path.exists():
        return []
    records: List[Dict] = []
    try:
        for line in path.read_text(encoding="utf-8").splitlines():
            try:
                record = json.loads(line)
            except json.JSONDecodeError:
                continue
            if isinstance(record, dict) and isinstance(record.get("problem_id"), int):
                records.append(record)
    except OSError:
        return []
    return records


def _write_records(path: Path, records: List[Dict]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    content = "".join(json.dumps(record, ensure_ascii=False) + "\n" for record in records)
    path.write_text(content, encoding="utf-8")


def enqueue(problem_id: int, *, reason: str = "rate_limited") -> Path:
    """Add a problem once, updating its last deferred timestamp if present."""
    path = queue_path()
    with _locked_queue(path) as lock_handle:
        fcntl.flock(lock_handle.fileno(), fcntl.LOCK_EX)
        records = _read_records(path)
        now = time.time()
        existing = next((item for item in records if item.get("problem_id") == problem_id), None)
        if existing is None:
            records.append(
                {
                    "problem_id": problem_id,
                    "queued_at": now,
                    "last_reason": reason,
                    "defer_count": 1,
                }
            )
        else:
            existing["last_deferred_at"] = now
            existing["last_reason"] = reason
            existing["defer_count"] = int(existing.get("defer_count", 1)) + 1
        _write_records(path, records)
        fcntl.flock(lock_handle.fileno(), fcntl.LOCK_UN)
    return path


def pending_records() -> List[Dict]:
    """Return all queued records, including entries in quarantine."""
    path = queue_path()
    with _locked_queue(path) as lock_handle:
        fcntl.flock(lock_handle.fileno(), fcntl.LOCK_SH)
        records = _read_records(path)
        fcntl.flock(lock_handle.fileno(), fcntl.LOCK_UN)
    return records


def pending_problem_ids() -> List[int]:
    return [int(item["problem_id"]) for item in pending_records()]


def eligible_problem_ids(*, now: float | None = None) -> List[int]:
    """Return queued IDs whose quarantine window has elapsed."""
    current_time = time.time() if now is None else now
    return [
        int(item["problem_id"])
        for item in pending_records()
        if float(item.get("next_attempt_at", 0.0)) <= current_time
    ]


def uncertain_hold_seconds() -> float:
    """Read the quarantine duration for an uncertain submission result."""
    configured = os.getenv("AI_SOLVER_SUBMIT_UNCERTAIN_HOLD", "3600")
    try:
        return max(60.0, float(configured))
    except ValueError:
        return 3600.0


def defer(
    problem_id: int,
    *,
    reason: str,
    delay_seconds: float | None = None,
) -> None:
    """Quarantine a queued item without removing it from durable storage."""
    path = queue_path()
    with _locked_queue(path) as lock_handle:
        fcntl.flock(lock_handle.fileno(), fcntl.LOCK_EX)
        records = _read_records(path)
        now = time.time()
        hold_seconds = (
            uncertain_hold_seconds()
            if delay_seconds is None
            else max(60.0, delay_seconds)
        )
        hold_until = now + hold_seconds
        for record in records:
            if record.get("problem_id") != problem_id:
                continue
            record["last_deferred_at"] = now
            record["last_reason"] = reason
            record["defer_count"] = int(record.get("defer_count", 1)) + 1
            record["next_attempt_at"] = max(
                float(record.get("next_attempt_at", 0.0)), hold_until
            )
            break
        _write_records(path, records)
        fcntl.flock(lock_handle.fileno(), fcntl.LOCK_UN)


def remove(problem_id: int) -> None:
    path = queue_path()
    with _locked_queue(path) as lock_handle:
        fcntl.flock(lock_handle.fileno(), fcntl.LOCK_EX)
        _write_records(
            path,
            [item for item in _read_records(path) if item.get("problem_id") != problem_id],
        )
        fcntl.flock(lock_handle.fileno(), fcntl.LOCK_UN)
