#include <gtest/gtest.h>
#include "leetcode/problems/find-target-indices-after-sorting-array.h"

using namespace leetcode::problem_2089;

class FindTargetIndicesAfterSortingArrayTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  FindTargetIndicesAfterSortingArraySolution solution;
};

TEST_P(FindTargetIndicesAfterSortingArrayTest, Example1) {
  std::vector<int> nums = {1, 2, 5, 2, 3};
  int target = 2;
  std::vector<int> expected = {1, 2};
  EXPECT_EQ(solution.targetIndices(nums, target), expected);
}

TEST_P(FindTargetIndicesAfterSortingArrayTest, Example2) {
  std::vector<int> nums = {1, 2, 5, 2, 3};
  int target = 3;
  std::vector<int> expected = {3};
  EXPECT_EQ(solution.targetIndices(nums, target), expected);
}

TEST_P(FindTargetIndicesAfterSortingArrayTest, Example3) {
  std::vector<int> nums = {1, 2, 5, 2, 3};
  int target = 5;
  std::vector<int> expected = {4};
  EXPECT_EQ(solution.targetIndices(nums, target), expected);
}

TEST_P(FindTargetIndicesAfterSortingArrayTest, SelfAuthoredTargetNotPresent) {
  std::vector<int> nums = {1, 3, 5};
  int target = 2;
  std::vector<int> expected = {};
  EXPECT_EQ(solution.targetIndices(nums, target), expected);
}

TEST_P(FindTargetIndicesAfterSortingArrayTest, SelfAuthoredAllElementsAreTarget) {
  std::vector<int> nums = {2, 2, 2};
  int target = 2;
  std::vector<int> expected = {0, 1, 2};
  EXPECT_EQ(solution.targetIndices(nums, target), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindTargetIndicesAfterSortingArrayTest,
    testing::ValuesIn(
        FindTargetIndicesAfterSortingArraySolution().getStrategyNames()));
