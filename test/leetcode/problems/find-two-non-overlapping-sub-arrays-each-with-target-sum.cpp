#include <gtest/gtest.h>

#include "leetcode/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum.h"

using namespace leetcode::problem_1477;

class FindTwoNonOverlappingSubArraysEachWithTargetSumTest : public testing::TestWithParam<std::string> {
 protected:
  FindTwoNonOverlappingSubArraysEachWithTargetSumSolution solution;
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(FindTwoNonOverlappingSubArraysEachWithTargetSumTest, Example1) {
  std::vector<int> arr = {3, 2, 2, 4, 3};
  int target = 3;
  EXPECT_EQ(solution.minSumOfLengths(arr, target), 2);
}

TEST_P(FindTwoNonOverlappingSubArraysEachWithTargetSumTest, Example2) {
  std::vector<int> arr = {7, 3, 4, 7};
  int target = 7;
  EXPECT_EQ(solution.minSumOfLengths(arr, target), 2);
}

TEST_P(FindTwoNonOverlappingSubArraysEachWithTargetSumTest, Example3) {
  std::vector<int> arr = {4, 3, 2, 6, 2, 3, 4};
  int target = 6;
  EXPECT_EQ(solution.minSumOfLengths(arr, target), -1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindTwoNonOverlappingSubArraysEachWithTargetSumTest,
    testing::ValuesIn(FindTwoNonOverlappingSubArraysEachWithTargetSumSolution().getStrategyNames()));