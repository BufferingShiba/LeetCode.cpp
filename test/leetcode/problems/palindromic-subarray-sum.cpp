#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/palindromic-subarray-sum.h"

namespace leetcode {
namespace problem_3985 {

class PalindromicSubarraySumTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PalindromicSubarraySumSolution solution;
};

TEST_P(PalindromicSubarraySumTest, Example1) {
  std::vector<int> nums = {10, 10};
  EXPECT_EQ(20, solution.getSum(nums));
}

TEST_P(PalindromicSubarraySumTest, Example2) {
  std::vector<int> nums = {1, 2, 3, 2, 1, 5, 6};
  EXPECT_EQ(9, solution.getSum(nums));
}

TEST_P(PalindromicSubarraySumTest, Example3) {
  std::vector<int> nums = {7, 1, 2, 1, 7, 3, 4, 3, 4};
  EXPECT_EQ(18, solution.getSum(nums));
}

TEST_P(PalindromicSubarraySumTest, Example4) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  EXPECT_EQ(5, solution.getSum(nums));
}

TEST_P(PalindromicSubarraySumTest, Example5) {
  std::vector<int> nums = {1000};
  EXPECT_EQ(1000, solution.getSum(nums));
}

TEST_P(PalindromicSubarraySumTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  EXPECT_EQ(5, solution.getSum(nums));
}

TEST_P(PalindromicSubarraySumTest, SelfAuthoredAllEqualEven) {
  std::vector<int> nums = {3, 3, 3, 3};
  EXPECT_EQ(12, solution.getSum(nums));
}

INSTANTIATE_TEST_SUITE_P(
    PalindromicSubarraySumTests, PalindromicSubarraySumTest,
    ::testing::ValuesIn(PalindromicSubarraySumSolution().getStrategyNames()));

}  // namespace problem_3985
}  // namespace leetcode
