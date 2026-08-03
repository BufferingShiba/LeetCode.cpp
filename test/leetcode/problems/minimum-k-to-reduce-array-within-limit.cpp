#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/minimum-k-to-reduce-array-within-limit.h"

using namespace leetcode::problem_3824;

class MinimumKToReduceArrayWithinLimitTest
    : public testing::TestWithParam<std::string> {
 protected:
  MinimumKToReduceArrayWithinLimitSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MinimumKToReduceArrayWithinLimitTest, Example1) {
  std::vector<int> nums = {3, 7, 5};
  EXPECT_EQ(solution.minimumK(nums), 3);
}

TEST_P(MinimumKToReduceArrayWithinLimitTest, Example2) {
  std::vector<int> nums = {1};
  EXPECT_EQ(solution.minimumK(nums), 1);
}

TEST_P(MinimumKToReduceArrayWithinLimitTest, AllOnes) {
  std::vector<int> nums(100, 1);  // n=100, sqrt=10, need k≥10
  EXPECT_EQ(solution.minimumK(nums), 10);
}

TEST_P(MinimumKToReduceArrayWithinLimitTest, SingleLarge) {
  std::vector<int> nums = {100000};
  // k=47: ceil(100000/47)=2128, 47^2=2209 → works
  EXPECT_EQ(solution.minimumK(nums), 47);
}

TEST_P(MinimumKToReduceArrayWithinLimitTest, LargeUniform) {
  std::vector<int> nums = {10, 10, 10, 10, 10};
  // k=3: ceil(10/3)=4 each, total=20, 9<20 → fails
  // k=4: ceil(10/4)=3 each, total=15, 16≥15 → works
  EXPECT_EQ(solution.minimumK(nums), 4);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumKToReduceArrayWithinLimitTest,
    testing::ValuesIn(
        MinimumKToReduceArrayWithinLimitSolution().getStrategyNames()));
