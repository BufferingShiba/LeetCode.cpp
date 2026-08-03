#include "leetcode/problems/apply-operations-on-array-to-maximize-sum-of-squares.h"

#include <gtest/gtest.h>

namespace leetcode::problem_2897 {

class ApplyOperationsOnArrayToMaximizeSumOfSquaresTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ApplyOperationsOnArrayToMaximizeSumOfSquaresSolution solution_;
};

TEST_P(ApplyOperationsOnArrayToMaximizeSumOfSquaresTest, Example1) {
  std::vector<int> nums{2, 6, 5, 8};
  int k = 2;
  EXPECT_EQ(solution_.maxSum(nums, k), 261);
}

TEST_P(ApplyOperationsOnArrayToMaximizeSumOfSquaresTest, Example2) {
  std::vector<int> nums{4, 5, 4, 7};
  int k = 3;
  EXPECT_EQ(solution_.maxSum(nums, k), 90);
}

TEST_P(ApplyOperationsOnArrayToMaximizeSumOfSquaresTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{7};
  int k = 1;
  EXPECT_EQ(solution_.maxSum(nums, k), 49);
}

TEST_P(ApplyOperationsOnArrayToMaximizeSumOfSquaresTest, SelfAuthoredAllSameBits) {
  // nums = [3,3,3], k=2 -> each bit total count = 3, so two numbers = 3 -> 9+9
  std::vector<int> nums{3, 3, 3};
  int k = 2;
  EXPECT_EQ(solution_.maxSum(nums, k), 18);
}

INSTANTIATE_TEST_SUITE_P(
    ApplyOperationsOnArrayToMaximizeSumOfSquaresTestSuite,
    ApplyOperationsOnArrayToMaximizeSumOfSquaresTest,
    ::testing::ValuesIn(
        ApplyOperationsOnArrayToMaximizeSumOfSquaresSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_2897
