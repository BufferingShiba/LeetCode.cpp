#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/check-if-it-is-possible-to-split-array.h"

namespace leetcode {
namespace problem_2811 {
namespace {

class CheckIfItIsPossibleToSplitArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  CheckIfItIsPossibleToSplitArraySolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(CheckIfItIsPossibleToSplitArrayTest, Example1) {
  std::vector<int> nums = {2, 2, 1};
  int m = 4;
  EXPECT_TRUE(solution.canSplitArray(nums, m));
}

TEST_P(CheckIfItIsPossibleToSplitArrayTest, Example2) {
  std::vector<int> nums = {2, 1, 3};
  int m = 5;
  EXPECT_FALSE(solution.canSplitArray(nums, m));
}

TEST_P(CheckIfItIsPossibleToSplitArrayTest, Example3) {
  std::vector<int> nums = {2, 3, 3, 2, 3};
  int m = 6;
  EXPECT_TRUE(solution.canSplitArray(nums, m));
}

TEST_P(CheckIfItIsPossibleToSplitArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  int m = 10;
  EXPECT_TRUE(solution.canSplitArray(nums, m));
}

TEST_P(CheckIfItIsPossibleToSplitArrayTest, SelfAuthoredTwoElements) {
  std::vector<int> nums = {1, 1};
  int m = 3;
  EXPECT_TRUE(solution.canSplitArray(nums, m));
}

}  // namespace

INSTANTIATE_TEST_SUITE_P(
    CheckIfItIsPossibleToSplitArrayTestSuite,
    CheckIfItIsPossibleToSplitArrayTest,
    ::testing::ValuesIn(CheckIfItIsPossibleToSplitArraySolution().getStrategyNames()));

}  // namespace problem_2811
}  // namespace leetcode
