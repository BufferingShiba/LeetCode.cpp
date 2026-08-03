#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-subsequence-of-length-k-with-the-largest-sum.h"

namespace leetcode {
namespace problem_2099 {

using FindSubsequenceOfLengthKWithTheLargestSumTest =
    ::testing::TestWithParam<std::string>;

TEST_P(FindSubsequenceOfLengthKWithTheLargestSumTest, Example1) {
  FindSubsequenceOfLengthKWithTheLargestSumSolution solution;
  solution.setStrategy(GetParam());
  std::vector<int> nums = {2, 1, 3, 3};
  EXPECT_EQ(solution.maxSubsequence(nums, 2), std::vector<int>({3, 3}));
}

TEST_P(FindSubsequenceOfLengthKWithTheLargestSumTest, Example2) {
  FindSubsequenceOfLengthKWithTheLargestSumSolution solution;
  solution.setStrategy(GetParam());
  std::vector<int> nums = {-1, -2, 3, 4};
  EXPECT_EQ(solution.maxSubsequence(nums, 3), std::vector<int>({-1, 3, 4}));
}

TEST_P(FindSubsequenceOfLengthKWithTheLargestSumTest, Example3) {
  FindSubsequenceOfLengthKWithTheLargestSumSolution solution;
  solution.setStrategy(GetParam());
  std::vector<int> nums = {3, 4, 3, 3};
  EXPECT_EQ(solution.maxSubsequence(nums, 2), std::vector<int>({3, 4}));
}

TEST_P(FindSubsequenceOfLengthKWithTheLargestSumTest, SelfAuthoredAllNegative) {
  FindSubsequenceOfLengthKWithTheLargestSumSolution solution;
  solution.setStrategy(GetParam());
  std::vector<int> nums = {-5, -1, -3};
  EXPECT_EQ(solution.maxSubsequence(nums, 2), std::vector<int>({-1, -3}));
}

TEST_P(FindSubsequenceOfLengthKWithTheLargestSumTest, SelfAuthoredAllEqualToK) {
  FindSubsequenceOfLengthKWithTheLargestSumSolution solution;
  solution.setStrategy(GetParam());
  std::vector<int> nums = {6, 2, 9, 4};
  EXPECT_EQ(solution.maxSubsequence(nums, 4), std::vector<int>({6, 2, 9, 4}));
}

INSTANTIATE_TEST_SUITE_P(
    FindSubsequenceOfLengthKWithTheLargestSumTests,
    FindSubsequenceOfLengthKWithTheLargestSumTest,
    ::testing::ValuesIn(
        FindSubsequenceOfLengthKWithTheLargestSumSolution().getStrategyNames()));

}  // namespace problem_2099
}  // namespace leetcode
