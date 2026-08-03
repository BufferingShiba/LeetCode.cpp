#include <gtest/gtest.h>

#include "leetcode/problems/wiggle-sort-ii.h"

#include <vector>

namespace leetcode::problem_324 {
namespace {

bool isValidWiggle(const std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  for (int i = 1; i < n; i += 2) {
    if (!(nums[i - 1] < nums[i])) return false;
    if (i + 1 < n && !(nums[i] > nums[i + 1])) return false;
  }
  return true;
}

}  // namespace

class WiggleSortIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  WiggleSortIiSolution solution;
};

TEST_P(WiggleSortIiTest, Example1) {
  std::vector<int> nums = {1, 5, 1, 1, 6, 4};
  solution.wiggleSort(nums);
  EXPECT_TRUE(isValidWiggle(nums));
}

TEST_P(WiggleSortIiTest, Example2) {
  std::vector<int> nums = {1, 3, 2, 2, 3, 1};
  solution.wiggleSort(nums);
  EXPECT_TRUE(isValidWiggle(nums));
}

TEST_P(WiggleSortIiTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {1};
  solution.wiggleSort(nums);
  EXPECT_TRUE(isValidWiggle(nums));
}

TEST_P(WiggleSortIiTest, SelfAuthoredTwoElements) {
  std::vector<int> nums = {3, 5};
  solution.wiggleSort(nums);
  EXPECT_TRUE(isValidWiggle(nums));
}

TEST_P(WiggleSortIiTest, SelfAuthoredEqualLargeValue) {
  std::vector<int> nums = {1, 1, 1, 1, 2, 2, 2, 2};
  solution.wiggleSort(nums);
  EXPECT_TRUE(isValidWiggle(nums));
}

INSTANTIATE_TEST_SUITE_P(
    WiggleSortIiStrategies, WiggleSortIiTest,
    ::testing::ValuesIn(WiggleSortIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_324
