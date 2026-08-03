#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-maximum-divisibility-score.h"

namespace leetcode {
namespace problem_2644 {
namespace {

using FindTheMaximumDivisibilityScoreTest =
    ::testing::TestWithParam<std::string>;

}  // namespace

TEST_P(FindTheMaximumDivisibilityScoreTest, OfficialExamples) {
  FindTheMaximumDivisibilityScoreSolution solution;
  solution.setStrategy(GetParam());

  {
    std::vector<int> nums = {2, 9, 15, 50};
    std::vector<int> divisors = {5, 3, 7, 2};
    EXPECT_EQ(2, solution.maxDivScore(nums, divisors));
  }

  {
    std::vector<int> nums = {4, 7, 9, 3, 9};
    std::vector<int> divisors = {5, 2, 3};
    EXPECT_EQ(3, solution.maxDivScore(nums, divisors));
  }

  {
    std::vector<int> nums = {20, 14, 21, 10};
    std::vector<int> divisors = {10, 16, 20};
    EXPECT_EQ(10, solution.maxDivScore(nums, divisors));
  }
}

TEST_P(FindTheMaximumDivisibilityScoreTest, AllZeroScore) {
  FindTheMaximumDivisibilityScoreSolution solution;
  solution.setStrategy(GetParam());

  std::vector<int> nums = {7, 7};
  std::vector<int> divisors = {5, 3, 2};
  EXPECT_EQ(2, solution.maxDivScore(nums, divisors));
}

TEST_P(FindTheMaximumDivisibilityScoreTest, SingleElement) {
  FindTheMaximumDivisibilityScoreSolution solution;
  solution.setStrategy(GetParam());

  std::vector<int> nums = {8};
  std::vector<int> divisors = {4};
  EXPECT_EQ(4, solution.maxDivScore(nums, divisors));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheMaximumDivisibilityScoreTestSuite,
    FindTheMaximumDivisibilityScoreTest,
    ::testing::ValuesIn(FindTheMaximumDivisibilityScoreSolution().getStrategyNames()));

}  // namespace problem_2644
}  // namespace leetcode
