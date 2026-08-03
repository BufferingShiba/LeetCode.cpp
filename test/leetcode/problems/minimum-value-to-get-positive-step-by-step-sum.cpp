#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-value-to-get-positive-step-by-step-sum.h"

namespace leetcode::problem_1413 {

class MinimumValueToGetPositiveStepByStepSumTest
    : public ::testing::TestWithParam<std::string> {
 public:
  void SetUp() override { solution_.setStrategy(GetParam()); }

 protected:
  MinimumValueToGetPositiveStepByStepSumSolution solution_;
};

TEST_P(MinimumValueToGetPositiveStepByStepSumTest, Example1) {
  std::vector<int> nums = {-3, 2, -3, 4, 2};
  EXPECT_EQ(solution_.minStartValue(nums), 5);
}

TEST_P(MinimumValueToGetPositiveStepByStepSumTest, Example2) {
  std::vector<int> nums = {1, 2};
  EXPECT_EQ(solution_.minStartValue(nums), 1);
}

TEST_P(MinimumValueToGetPositiveStepByStepSumTest, Example3) {
  std::vector<int> nums = {1, -2, -3};
  EXPECT_EQ(solution_.minStartValue(nums), 5);
}

TEST_P(MinimumValueToGetPositiveStepByStepSumTest, SelfAuthoredAllNegative) {
  std::vector<int> nums = {-100, -100, -100};
  EXPECT_EQ(solution_.minStartValue(nums), 301);
}

TEST_P(MinimumValueToGetPositiveStepByStepSumTest, SelfAuthoredAllPositive) {
  std::vector<int> nums = {1, 5, 10};
  EXPECT_EQ(solution_.minStartValue(nums), 1);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumValueToGetPositiveStepByStepSumTestSuite,
    MinimumValueToGetPositiveStepByStepSumTest,
    ::testing::ValuesIn(
        MinimumValueToGetPositiveStepByStepSumSolution().getStrategyNames()));

}  // namespace leetcode::problem_1413
