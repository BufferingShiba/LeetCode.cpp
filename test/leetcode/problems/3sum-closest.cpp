#include "leetcode/problems/3sum-closest.h"

#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

using leetcode::problem_16::ThreeSumClosestSolution;

class ThreeSumClosestTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  ThreeSumClosestSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(ThreeSumClosestTest, Example1) {
  std::vector<int> nums{-1, 2, 1, -4};
  int target = 1;
  EXPECT_EQ(2, solution.threeSumClosest(nums, target));
}

TEST_P(ThreeSumClosestTest, Example2) {
  std::vector<int> nums{0, 0, 0};
  int target = 1;
  EXPECT_EQ(0, solution.threeSumClosest(nums, target));
}

INSTANTIATE_TEST_SUITE_P(
    ThreeSumClosestTestSuite, ThreeSumClosestTest,
    ::testing::ValuesIn(ThreeSumClosestSolution().getStrategyNames()));
