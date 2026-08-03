#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import unittest
from unittest.mock import MagicMock, patch

from script.leetcode.config import AIConfig, AIProvider
from script.leetcode.submit.submitter import LeetCodeSubmitter


class TestLeetCodeSubmitterInit(unittest.TestCase):
    def test_init_uses_cookie_prepare_helper(self) -> None:
        prepare = MagicMock(return_value=("csrftoken=c; LEETCODE_SESSION=s", "c"))
        with patch.dict(os.environ, {"LEETCODE_COOKIE": "raw-cookie"}, clear=True):
            with patch("script.leetcode.submit.submitter.load_dotenv", return_value=None):
                with patch("script.leetcode.submit.submitter.ProblemRepository"):
                    with patch.object(LeetCodeSubmitter, "_init_ai_client", return_value=None):
                        with patch.dict(
                            LeetCodeSubmitter.__init__.__globals__,
                            {"prepare_cookie": prepare},
                        ):
                            with patch(
                                "script.leetcode.submit.submitter.http_api.validate_cookie",
                                return_value=True,
                            ):
                                with patch("script.leetcode.submit.submitter.LeetCodeHttpClient"):
                                    submitter = LeetCodeSubmitter()

        prepare.assert_called_once_with("raw-cookie")
        self.assertEqual(submitter.cookie, "csrftoken=c; LEETCODE_SESSION=s")
        self.assertEqual(submitter.csrf_token, "c")

    def test_translation_client_has_hard_timeout(self) -> None:
        provider = AIProvider(
            name="deepseek",
            base_url="https://example.test/v1",
            model="deepseek-v4-flash",
            use_reasoner=False,
        )
        submitter = object.__new__(LeetCodeSubmitter)
        submitter.provider = provider
        with patch.dict(os.environ, {"DEEPSEEK_API_KEY": "test-key"}, clear=True):
            with patch.object(AIProvider, "from_env", return_value=provider):
                openai = MagicMock()
                with patch.dict(
                    LeetCodeSubmitter._init_ai_client.__globals__, {"OpenAI": openai}
                ):
                    submitter._init_ai_client()
                openai.assert_called_once_with(
                    api_key="test-key",
                    base_url="https://example.test/v1",
                    timeout=AIConfig.STREAM_TIMEOUT_SECONDS,
                )


if __name__ == "__main__":
    unittest.main()
