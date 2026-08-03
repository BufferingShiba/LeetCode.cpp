#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import unittest

from script.leetcode.problem_pool import ProblemPool


class TestProblemPoolSpecialTypes(unittest.TestCase):
    def _pool(self, problems):
        pool = ProblemPool.__new__(ProblemPool)
        pool._all_problems = problems
        pool._solved_slugs = set()
        pool._unsupported_cpp_slugs = set()
        return pool

    def test_skips_non_cpp_protocol_tags_but_keeps_normal_cpp_topics(self) -> None:
        pool = self._pool([
            {
                "titleSlug": "second-highest-salary",
                "questionFrontendId": "176",
                "difficulty": "Easy",
                "topicTags": [{"name": "Database"}],
            },
            {
                "titleSlug": "building-h2o",
                "questionFrontendId": "1117",
                "difficulty": "Medium",
                "topicTags": [{"name": "Concurrency"}],
            },
            {
                "titleSlug": "number-of-islands",
                "questionFrontendId": "200",
                "difficulty": "Medium",
                "topicTags": [{"name": "Graph Theory"}],
            },
        ])

        selected = pool._get_unsolved()

        self.assertEqual([item["titleSlug"] for item in selected], ["number-of-islands"])
        self.assertTrue(pool._is_skipped_special_problem(pool._all_problems[0]))
        self.assertFalse(pool._is_skipped_special_problem(pool._all_problems[2]))
        self.assertEqual(pool.get_stats()["skipped_special"], 2)


if __name__ == "__main__":
    unittest.main()
