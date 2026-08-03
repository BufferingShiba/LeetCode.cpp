#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/palindrome-partitioning-iii.h"

namespace leetcode::problem_1278 {

class PalindromePartitioningIiiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  PalindromePartitioningIiiSolution solution_;
};

TEST_P(PalindromePartitioningIiiTest, Example1) {
  EXPECT_EQ(solution_.palindromePartition("abc", 2), 1);
}

TEST_P(PalindromePartitioningIiiTest, Example2) {
  EXPECT_EQ(solution_.palindromePartition("aabbc", 3), 0);
}

TEST_P(PalindromePartitioningIiiTest, Example3) {
  EXPECT_EQ(solution_.palindromePartition("leetcode", 8), 0);
}

TEST_P(PalindromePartitioningIiiTest, SelfAuthoredSingleCharacter) {
  EXPECT_EQ(solution_.palindromePartition("a", 1), 0);
}

TEST_P(PalindromePartitioningIiiTest, SelfAuthoredAllSingleSubstrings) {
  // Each character is its own palindrome, zero changes needed.
  EXPECT_EQ(solution_.palindromePartition("abcdef", 6), 0);
}

INSTANTIATE_TEST_SUITE_P(
    PalindromePartitioningIiiTestCases, PalindromePartitioningIiiTest,
    ::testing::ValuesIn(PalindromePartitioningIiiSolution().getStrategyNames()));

}  // namespace leetcode::problem_1278
