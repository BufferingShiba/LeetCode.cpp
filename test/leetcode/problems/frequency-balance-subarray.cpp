#include "leetcode/problems/frequency-balance-subarray.h"

#include <gtest/gtest.h>

#include <vector>

namespace leetcode {
namespace problem_3960 {
namespace {

class FrequencyBalanceSubarrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FrequencyBalanceSubarraySolution solution;
};

TEST_P(FrequencyBalanceSubarrayTest, Example1) {
  std::vector<int> nums = {1, 2, 2, 1, 2, 3, 3, 3};
  EXPECT_EQ(solution.getLength(nums), 5);
}

TEST_P(FrequencyBalanceSubarrayTest, Example2) {
  std::vector<int> nums = {5, 5, 5, 5};
  EXPECT_EQ(solution.getLength(nums), 4);
}

TEST_P(FrequencyBalanceSubarrayTest, Example3) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(solution.getLength(nums), 1);
}

TEST_P(FrequencyBalanceSubarrayTest, SingleElement) {
  std::vector<int> nums = {42};
  EXPECT_EQ(solution.getLength(nums), 1);
}

TEST_P(FrequencyBalanceSubarrayTest, TwoBalancedFrequencies) {
  // [1,1,2] -> 1 twice, 2 once: f=1, and 2f=2, both present -> valid.
  std::vector<int> nums = {1, 1, 2};
  EXPECT_EQ(solution.getLength(nums), 3);
}

INSTANTIATE_TEST_SUITE_P(
    FrequencyBalanceSubarrayTests, FrequencyBalanceSubarrayTest,
    ::testing::ValuesIn(FrequencyBalanceSubarraySolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3960
}  // namespace leetcode
