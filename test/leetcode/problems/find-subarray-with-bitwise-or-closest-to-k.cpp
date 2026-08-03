#include <gtest/gtest.h>

#include "leetcode/problems/find-subarray-with-bitwise-or-closest-to-k.h"

using namespace leetcode::problem_3171;

class FindSubarrayWithBitwiseOrClosestToKTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
  FindSubarrayWithBitwiseOrClosestToKSolution solution;
};

TEST_P(FindSubarrayWithBitwiseOrClosestToKTest, Example1) {
  std::vector<int> nums = {1, 2, 4, 5};
  EXPECT_EQ(solution.minimumDifference(nums, 3), 0);
}

TEST_P(FindSubarrayWithBitwiseOrClosestToKTest, Example2) {
  std::vector<int> nums = {1, 3, 1, 3};
  EXPECT_EQ(solution.minimumDifference(nums, 2), 1);
}

TEST_P(FindSubarrayWithBitwiseOrClosestToKTest, Example3) {
  std::vector<int> nums = {1};
  EXPECT_EQ(solution.minimumDifference(nums, 10), 9);
}

INSTANTIATE_TEST_SUITE_P(Strategies, FindSubarrayWithBitwiseOrClosestToKTest,
                         testing::ValuesIn(FindSubarrayWithBitwiseOrClosestToKSolution().getStrategyNames()));
