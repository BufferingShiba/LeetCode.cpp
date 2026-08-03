#include <gtest/gtest.h>

#include "leetcode/problems/palindrome-partitioning.h"

#include <string>
#include <vector>

namespace leetcode::problem_131 {

class PalindromePartitioningTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  PalindromePartitioningSolution solution;
};

TEST_P(PalindromePartitioningTest, Example1) {
  std::vector<std::vector<std::string>> expected = {{"a", "a", "b"}, {"aa", "b"}};
  EXPECT_EQ(solution.partition("aab"), expected);
}

TEST_P(PalindromePartitioningTest, Example2) {
  std::vector<std::vector<std::string>> expected = {{"a"}};
  EXPECT_EQ(solution.partition("a"), expected);
}

TEST_P(PalindromePartitioningTest, SelfAuthoredSinglePalindromeInput) {
  // "abba" is itself a palindrome; partitions: [a,b,b,a], [a,bb,a], [abba], [a,b,ba? no]...
  auto result = solution.partition("abba");
  std::vector<std::vector<std::string>> expected = {
      {"a", "b", "b", "a"}, {"a", "bb", "a"}, {"abba"}};
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    PalindromePartitioningTestSuite,
    PalindromePartitioningTest,
    ::testing::ValuesIn(PalindromePartitioningSolution().getStrategyNames()));

}  // namespace leetcode::problem_131
