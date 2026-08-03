#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/longest-subsequence-with-limited-sum.h"

namespace leetcode {
namespace problem_2389 {
namespace {

class LongestSubsequenceWithLimitedSumTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongestSubsequenceWithLimitedSumSolution solution;
};

TEST_P(LongestSubsequenceWithLimitedSumTest, Example1) {
  std::vector<int> nums = {4, 5, 2, 1};
  std::vector<int> queries = {3, 10, 21};
  std::vector<int> expected = {2, 3, 4};
  EXPECT_EQ(expected, solution.answerQueries(nums, queries));
}

TEST_P(LongestSubsequenceWithLimitedSumTest, Example2) {
  std::vector<int> nums = {2, 3, 4, 5};
  std::vector<int> queries = {1};
  std::vector<int> expected = {0};
  EXPECT_EQ(expected, solution.answerQueries(nums, queries));
}

TEST_P(LongestSubsequenceWithLimitedSumTest, SelfAuthoredSingleElementQueries) {
  std::vector<int> nums = {1};
  std::vector<int> queries = {0, 1, 5};
  std::vector<int> expected = {0, 1, 1};
  EXPECT_EQ(expected, solution.answerQueries(nums, queries));
}

INSTANTIATE_TEST_SUITE_P(
    LongestSubsequenceWithLimitedSumTestSuite,
    LongestSubsequenceWithLimitedSumTest,
    ::testing::ValuesIn(
        LongestSubsequenceWithLimitedSumSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2389
}  // namespace leetcode
