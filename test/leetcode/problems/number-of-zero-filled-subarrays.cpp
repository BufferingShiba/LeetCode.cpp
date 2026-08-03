#include "leetcode/problems/number-of-zero-filled-subarrays.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2348 {
namespace {

class NumberOfZeroFilledSubarraysTest
    : public ::testing::TestWithParam<std::string> {
 public:
  void SetUp() override { solution.setStrategy(GetParam()); }

 protected:
  NumberOfZeroFilledSubarraysSolution solution;
};

TEST_P(NumberOfZeroFilledSubarraysTest, Example1) {
  std::vector<int> nums = {1, 3, 0, 0, 2, 0, 0, 4};
  EXPECT_EQ(6, solution.zeroFilledSubarray(nums));
}

TEST_P(NumberOfZeroFilledSubarraysTest, Example2) {
  std::vector<int> nums = {0, 0, 0, 2, 0, 0};
  EXPECT_EQ(9, solution.zeroFilledSubarray(nums));
}

TEST_P(NumberOfZeroFilledSubarraysTest, Example3) {
  std::vector<int> nums = {2, 10, 2019};
  EXPECT_EQ(0, solution.zeroFilledSubarray(nums));
}

TEST_P(NumberOfZeroFilledSubarraysTest, SelfAuthoredSingleZero) {
  std::vector<int> nums = {0};
  EXPECT_EQ(1, solution.zeroFilledSubarray(nums));
}

TEST_P(NumberOfZeroFilledSubarraysTest, SelfAuthoredAllZeros) {
  std::vector<int> nums = {0, 0, 0, 0};
  EXPECT_EQ(10, solution.zeroFilledSubarray(nums));
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfZeroFilledSubarraysTestSuite, NumberOfZeroFilledSubarraysTest,
    ::testing::ValuesIn(NumberOfZeroFilledSubarraysSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2348
}  // namespace leetcode
