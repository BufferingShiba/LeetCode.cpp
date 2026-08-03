#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/max-pair-sum-in-an-array.h"

namespace leetcode {
namespace problem_2815 {
namespace {

class MaxPairSumInAnArrayTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaxPairSumInAnArraySolution solution_;
};

TEST_P(MaxPairSumInAnArrayTest, Example1) {
  std::vector<int> nums = {112, 131, 411};
  EXPECT_EQ(-1, solution_.maxSum(nums));
}

TEST_P(MaxPairSumInAnArrayTest, Example2) {
  std::vector<int> nums = {2536, 1613, 3366, 162};
  EXPECT_EQ(5902, solution_.maxSum(nums));
}

TEST_P(MaxPairSumInAnArrayTest, Example3) {
  std::vector<int> nums = {51, 71, 17, 24, 42};
  EXPECT_EQ(88, solution_.maxSum(nums));
}

TEST_P(MaxPairSumInAnArrayTest, PairWithTwoLargestNumbers) {
  std::vector<int> nums = {9, 19, 29, 12};
  // max digits: 9, 9, 9, 2 -> pair 29+19=48
  EXPECT_EQ(48, solution_.maxSum(nums));
}

TEST_P(MaxPairSumInAnArrayTest, AllSameMaxDigit) {
  std::vector<int> nums = {91, 92, 1};
  // max digits: 9, 9, 1 -> pair 92+91=183
  EXPECT_EQ(183, solution_.maxSum(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaxPairSumInAnArrayTestSuite, MaxPairSumInAnArrayTest,
    ::testing::ValuesIn(MaxPairSumInAnArraySolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2815
}  // namespace leetcode
