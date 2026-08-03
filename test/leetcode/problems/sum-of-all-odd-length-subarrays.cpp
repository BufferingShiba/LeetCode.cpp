#include <gtest/gtest.h>

#include "leetcode/problems/sum-of-all-odd-length-subarrays.h"

namespace leetcode {
namespace problem_1588 {

class SumOfAllOddLengthSubarraysTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SumOfAllOddLengthSubarraysSolution solution;
};

TEST_P(SumOfAllOddLengthSubarraysTest, Example1) {
  std::vector<int> arr = {1, 4, 2, 5, 3};
  EXPECT_EQ(solution.sumOddLengthSubarrays(arr), 58);
}

TEST_P(SumOfAllOddLengthSubarraysTest, Example2) {
  std::vector<int> arr = {1, 2};
  EXPECT_EQ(solution.sumOddLengthSubarrays(arr), 3);
}

TEST_P(SumOfAllOddLengthSubarraysTest, Example3) {
  std::vector<int> arr = {10, 11, 12};
  EXPECT_EQ(solution.sumOddLengthSubarrays(arr), 66);
}

TEST_P(SumOfAllOddLengthSubarraysTest, SelfAuthoredSingleElement) {
  std::vector<int> arr = {7};
  EXPECT_EQ(solution.sumOddLengthSubarrays(arr), 7);
}

TEST_P(SumOfAllOddLengthSubarraysTest, SelfAuthoredAllOnesLength4) {
  std::vector<int> arr = {1, 1, 1, 1};
  // len1: 4 → sum=4; len3: 2 subarrays → 3+3=6; total=10
  EXPECT_EQ(solution.sumOddLengthSubarrays(arr), 10);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    SumOfAllOddLengthSubarraysTest,
    ::testing::ValuesIn(
        SumOfAllOddLengthSubarraysSolution().getStrategyNames()));

}  // namespace problem_1588
}  // namespace leetcode
