#include <gtest/gtest.h>
#include <vector>

#include "leetcode/problems/longest-subsequence-with-non-zero-bitwise-xor.h"

namespace leetcode {
namespace problem_3702 {
namespace {

class LongestSubsequenceWithNonZeroBitwiseXorTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongestSubsequenceWithNonZeroBitwiseXorSolution solution;
};

TEST_P(LongestSubsequenceWithNonZeroBitwiseXorTest, Example1) {
  std::vector<int> nums = {1, 2, 3};
  EXPECT_EQ(solution.longestSubsequence(nums), 2);
}

TEST_P(LongestSubsequenceWithNonZeroBitwiseXorTest, Example2) {
  std::vector<int> nums = {2, 3, 4};
  EXPECT_EQ(solution.longestSubsequence(nums), 3);
}

TEST_P(LongestSubsequenceWithNonZeroBitwiseXorTest, SelfAuthoredSingleNonZero) {
  std::vector<int> nums = {5};
  // total XOR = 5 != 0 -> answer 1
  EXPECT_EQ(solution.longestSubsequence(nums), 1);
}

TEST_P(LongestSubsequenceWithNonZeroBitwiseXorTest, SelfAuthoredSingleZero) {
  std::vector<int> nums = {0};
  // total XOR = 0, all zero -> 0
  EXPECT_EQ(solution.longestSubsequence(nums), 0);
}

TEST_P(LongestSubsequenceWithNonZeroBitwiseXorTest, SelfAuthoredAllZeros) {
  std::vector<int> nums = {0, 0, 0};
  // all zero -> 0
  EXPECT_EQ(solution.longestSubsequence(nums), 0);
}

TEST_P(LongestSubsequenceWithNonZeroBitwiseXorTest, SelfAuthoredTotalXorZeroWithNonZero) {
  std::vector<int> nums = {7, 7};
  // total XOR = 0, drop one 7 (non-zero) -> remaining XOR = 7 != 0 -> n-1 = 1
  EXPECT_EQ(solution.longestSubsequence(nums), 1);
}

TEST_P(LongestSubsequenceWithNonZeroBitwiseXorTest, SelfAuthoredThreeElementsXorZero) {
  std::vector<int> nums = {1, 2, 3};
  // total XOR = 0, has non-zero -> n-1 = 2
  EXPECT_EQ(solution.longestSubsequence(nums), 2);
}

INSTANTIATE_TEST_SUITE_P(
    LongestSubsequenceWithNonZeroBitwiseXorTestSuite,
    LongestSubsequenceWithNonZeroBitwiseXorTest,
    ::testing::ValuesIn(
        LongestSubsequenceWithNonZeroBitwiseXorSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3702
}  // namespace leetcode
