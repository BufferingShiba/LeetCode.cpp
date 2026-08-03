#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import io
import json
import unittest
import urllib.error
from unittest.mock import patch

from script.leetcode.api.client import GraphQLClient
from script.leetcode.exceptions import APIError, NetworkError
from script.leetcode.models import ProblemData


class FakeResponse:
    def __init__(self, payload: dict):
        self._payload = payload

    def read(self) -> bytes:
        return json.dumps(self._payload).encode("utf-8")

    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc, tb):
        return False


class FakeCache:
    def __init__(self, data=None):
        self._data = data or {}
        self.saved = {}

    def get_or_compute(self, key, compute_func, expiry_seconds=None):
        if key in self._data:
            return self._data[key]
        value = compute_func()
        self._data[key] = value
        return value

    def save(self, key, value):
        self.saved[key] = value

    def clear(self):
        self._data.clear()


class TestGraphQLClientQuery(unittest.TestCase):
    @patch("time.sleep", return_value=None)
    @patch("urllib.request.urlopen")
    def test_query_retries_then_success(self, mock_urlopen, _mock_sleep) -> None:
        client = GraphQLClient()
        client._cache = FakeCache()

        mock_urlopen.side_effect = [
            urllib.error.URLError("temporary down"),
            FakeResponse({"data": {"ok": True}}),
        ]

        result = client.query("query { ping }", max_retries=2)
        self.assertEqual(result["data"]["ok"], True)
        self.assertEqual(mock_urlopen.call_count, 2)

    @patch("time.sleep", return_value=None)
    @patch("urllib.request.urlopen")
    def test_query_http_error_raises_api_error(self, mock_urlopen, _mock_sleep) -> None:
        client = GraphQLClient()
        client._cache = FakeCache()

        http_error = urllib.error.HTTPError(
            url="https://leetcode.com/graphql",
            code=500,
            msg="internal error",
            hdrs=None,
            fp=io.BytesIO(b"boom"),
        )
        mock_urlopen.side_effect = http_error

        with self.assertRaises(APIError):
            client.query("query { ping }", max_retries=1)

    @patch("time.sleep", return_value=None)
    @patch("urllib.request.urlopen")
    def test_query_url_error_raises_network_error(self, mock_urlopen, _mock_sleep) -> None:
        client = GraphQLClient()
        client._cache = FakeCache()
        mock_urlopen.side_effect = urllib.error.URLError("dns fail")

        with self.assertRaises(NetworkError):
            client.query("query { ping }", max_retries=1)


class TestGraphQLClientInternals(unittest.TestCase):
    def test_get_id_to_slug_map_converts_string_keys(self) -> None:
        client = GraphQLClient()
        cache = FakeCache({"id_to_slug_map": {"1": "two-sum", "2": "add-two-numbers"}})
        client._cache = cache

        mapping = client._get_id_to_slug_map()
        self.assertEqual(mapping[1], "two-sum")
        self.assertEqual(mapping[2], "add-two-numbers")
        self.assertIn("id_to_slug_map", cache.saved)
        self.assertEqual(cache.saved["id_to_slug_map"], mapping)

    def test_get_problem_by_id_rebuilds_stale_public_id_mapping(self) -> None:
        client = GraphQLClient()
        client._cache = FakeCache({"id_to_slug_map": {2188: "stale-slug"}})
        stale = ProblemData(
            question_id="2188",
            question_frontend_id="2064",
            title="stale",
            title_slug="stale-slug",
            difficulty="Medium",
            is_paid_only=False,
        )
        current = ProblemData(
            question_id="2295",
            question_frontend_id="2188",
            title="Minimum Time to Finish the Race",
            title_slug="minimum-time-to-finish-the-race",
            difficulty="Hard",
            is_paid_only=False,
        )

        with patch.object(client, "get_problem_by_slug", side_effect=[stale, current]):
            with patch.object(client, "get_all_problems", return_value=[current]):
                result = client.get_problem_by_id("2188")

        self.assertEqual(result.id, 2188)
        self.assertEqual(result.slug, "minimum-time-to-finish-the-race")
        self.assertEqual(
            client._cache.saved["id_to_slug_map"],
            {2188: "minimum-time-to-finish-the-race"},
        )


if __name__ == "__main__":
    unittest.main()
