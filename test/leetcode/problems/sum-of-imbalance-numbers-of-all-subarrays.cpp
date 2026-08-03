#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/sum-of-imbalance-numbers-of-all-subarrays.h"

namespace leetcode {
namespace problem_2763 {

using SumOfImbalanceNumbersOfAllSubarraysTest = ::testing::TestWithParam<std::string>;

class SumImbalanceNumbersFixture : public SumOfImbalanceNumbersOfAllSubarraysTest {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  SumOfImbalanceNumbersOfAllSubarraysSolution solution;
};

TEST_P(SumImbalanceNumbersFixture, Example1) {
  std::vector<int> nums = {2, 3, 1, 4};
  EXPECT_EQ(3, solution.sumImbalanceNumbers(nums));
}

TEST_P(SumImbalanceNumbersFixture, Example2) {
  std::vector<int> nums = {1, 3, 3, 3, 5};
  EXPECT_EQ(8, solution.sumImbalanceNumbers(nums));
}

TEST_P(SumImbalanceNumbersFixture, SelfAuthoredSingleElement) {
  std::vector<int> nums = {7};
  EXPECT_EQ(0, solution.sumImbalanceNumbers(nums));
}

TEST_P(SumImbalanceNumbersFixture, SelfAuthoredAllEqual) {
  std::vector<int> nums = {2, 2, 2};
  EXPECT_EQ(0, solution.sumImbalanceNumbers(nums));
}

TEST_P(SumImbalanceNumbersFixture, SelfAuthoredConsecutiveRun) {
  std::vector<int> nums = {1, 2, 3};
  // Every subarray consists of a contiguous range; imbalance 0 everywhere.
  EXPECT_EQ(0, solution.sumImbalanceNumbers(nums));
}

INSTANTIATE_TEST_SUITE_P(
    SumOfImbalanceNumbersOfAllSubarrays,
    SumImbalanceNumbersFixture,
    ::testing::ValuesIn(SumOfImbalanceNumbersOfAllSubarraysSolution().getStrategyNames()));

}  // namespace problem_2763
}  // namespace leetcode
