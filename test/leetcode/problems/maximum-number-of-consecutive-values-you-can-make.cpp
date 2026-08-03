#include "leetcode/problems/maximum-number-of-consecutive-values-you-can-make.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1798 {
namespace {

class MaximumNumberOfConsecutiveValuesYouCanMakeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumNumberOfConsecutiveValuesYouCanMakeSolution solution;
};

TEST_P(MaximumNumberOfConsecutiveValuesYouCanMakeTest, Example1) {
  std::vector<int> coins = {1, 3};
  EXPECT_EQ(2, solution.getMaximumConsecutive(coins));
}

TEST_P(MaximumNumberOfConsecutiveValuesYouCanMakeTest, Example2) {
  std::vector<int> coins = {1, 1, 1, 4};
  EXPECT_EQ(8, solution.getMaximumConsecutive(coins));
}

TEST_P(MaximumNumberOfConsecutiveValuesYouCanMakeTest, Example3) {
  std::vector<int> coins = {1, 4, 10, 3, 1};
  EXPECT_EQ(20, solution.getMaximumConsecutive(coins));
}

TEST_P(MaximumNumberOfConsecutiveValuesYouCanMakeTest, SelfAuthoredSingleCoinOne) {
  std::vector<int> coins = {1};
  EXPECT_EQ(2, solution.getMaximumConsecutive(coins));
}

TEST_P(MaximumNumberOfConsecutiveValuesYouCanMakeTest, SelfAuthoredNoOneCoin) {
  std::vector<int> coins = {2};
  EXPECT_EQ(1, solution.getMaximumConsecutive(coins));  // 只能构造 0
}

TEST_P(MaximumNumberOfConsecutiveValuesYouCanMakeTest, SelfAuthoredGapBreaksContinuity) {
  std::vector<int> coins = {1, 2, 5};
  // 0..3 可构造，4 无法构造 -> 共4个
  EXPECT_EQ(4, solution.getMaximumConsecutive(coins));
}

TEST_P(MaximumNumberOfConsecutiveValuesYouCanMakeTest, SelfAuthoredAllSameOnes) {
  std::vector<int> coins = {1, 1, 1, 1};
  EXPECT_EQ(5, solution.getMaximumConsecutive(coins));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfConsecutiveValuesYouCanMakeTestCases,
    MaximumNumberOfConsecutiveValuesYouCanMakeTest,
    ::testing::ValuesIn(
        MaximumNumberOfConsecutiveValuesYouCanMakeSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1798
}  // namespace leetcode
