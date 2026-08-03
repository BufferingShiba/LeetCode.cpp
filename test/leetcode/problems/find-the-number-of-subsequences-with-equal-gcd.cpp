#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-number-of-subsequences-with-equal-gcd.h"

namespace leetcode {
namespace problem_3336 {
namespace {

using FindTheNumberOfSubsequencesWithEqualGcdTest =
    ::testing::TestWithParam<std::string>;

}  // namespace

TEST_P(FindTheNumberOfSubsequencesWithEqualGcdTest, Example1) {
  FindTheNumberOfSubsequencesWithEqualGcdSolution solution;
  solution.setStrategy(GetParam());
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(solution.subsequencePairCount(nums), 10);
}

TEST_P(FindTheNumberOfSubsequencesWithEqualGcdTest, Example2) {
  FindTheNumberOfSubsequencesWithEqualGcdSolution solution;
  solution.setStrategy(GetParam());
  std::vector<int> nums = {10, 20, 30};
  EXPECT_EQ(solution.subsequencePairCount(nums), 2);
}

TEST_P(FindTheNumberOfSubsequencesWithEqualGcdTest, Example3) {
  FindTheNumberOfSubsequencesWithEqualGcdSolution solution;
  solution.setStrategy(GetParam());
  std::vector<int> nums = {1, 1, 1, 1};
  EXPECT_EQ(solution.subsequencePairCount(nums), 50);
}

TEST_P(FindTheNumberOfSubsequencesWithEqualGcdTest, SelfAuthoredSingleElement) {
  FindTheNumberOfSubsequencesWithEqualGcdSolution solution;
  solution.setStrategy(GetParam());
  // n=1: both subsequences must be non-empty and disjoint; impossible.
  std::vector<int> nums = {5};
  EXPECT_EQ(solution.subsequencePairCount(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheNumberOfSubsequencesWithEqualGcd,
    FindTheNumberOfSubsequencesWithEqualGcdTest,
    ::testing::ValuesIn(
        FindTheNumberOfSubsequencesWithEqualGcdSolution().getStrategyNames()));

}  // namespace problem_3336
}  // namespace leetcode
