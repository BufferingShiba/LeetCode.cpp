#include "leetcode/problems/next-permutation.h"
#include <gtest/gtest.h>

namespace leetcode {
namespace problem_31 {

class NextPermutationTest : public ::testing::TestWithParam<std::string> {
 protected:
  NextPermutationSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(NextPermutationTest, Example1) {
  std::vector<int> nums = {1, 2, 3};
  solution.nextPermutation(nums);
  std::vector<int> expected = {1, 3, 2};
  EXPECT_EQ(nums, expected);
}

TEST_P(NextPermutationTest, Example2) {
  std::vector<int> nums = {3, 2, 1};
  solution.nextPermutation(nums);
  std::vector<int> expected = {1, 2, 3};
  EXPECT_EQ(nums, expected);
}

TEST_P(NextPermutationTest, Example3) {
  std::vector<int> nums = {1, 1, 5};
  solution.nextPermutation(nums);
  std::vector<int> expected = {1, 5, 1};
  EXPECT_EQ(nums, expected);
}

TEST_P(NextPermutationTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {1};
  solution.nextPermutation(nums);
  std::vector<int> expected = {1};
  EXPECT_EQ(nums, expected);
}

TEST_P(NextPermutationTest, SelfAuthoredDuplicateElements) {
  std::vector<int> nums = {1, 1};
  solution.nextPermutation(nums);
  std::vector<int> expected = {1, 1};
  EXPECT_EQ(nums, expected);
}

INSTANTIATE_TEST_SUITE_P(
    NextPermutationStrategies, NextPermutationTest,
    ::testing::ValuesIn(NextPermutationSolution().getStrategyNames()));

}  // namespace problem_31
}  // namespace leetcode
