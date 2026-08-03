#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/check-if-dfs-strings-are-palindromes.h"

namespace leetcode {
namespace problem_3327 {

class CheckIfDfsStringsArePalindromesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CheckIfDfsStringsArePalindromesSolution solution;
};

TEST_P(CheckIfDfsStringsArePalindromesTest, Example1) {
  std::vector<int> parent = {-1, 0, 0, 1, 1, 2};
  std::string s = "aababa";
  std::vector<bool> expected = {true, true, false, true, true, true};
  EXPECT_EQ(solution.findAnswer(parent, s), expected);
}

TEST_P(CheckIfDfsStringsArePalindromesTest, Example2) {
  std::vector<int> parent = {-1, 0, 0, 0, 0};
  std::string s = "aabcb";
  std::vector<bool> expected = {true, true, true, true, true};
  EXPECT_EQ(solution.findAnswer(parent, s), expected);
}

TEST_P(CheckIfDfsStringsArePalindromesTest, SelfAuthoredSingleNode) {
  std::vector<int> parent = {-1};
  std::string s = "z";
  std::vector<bool> expected = {true};
  EXPECT_EQ(solution.findAnswer(parent, s), expected);
}

TEST_P(CheckIfDfsStringsArePalindromesTest, SelfAuthoredLinearChain) {
  // 0 -> 1 -> 2 -> 3, s = "abba".
  std::vector<int> parent = {-1, 0, 1, 2};
  std::string s = "abba";
  std::vector<bool> expected = {true, false, false, true};
  EXPECT_EQ(solution.findAnswer(parent, s), expected);
}

TEST_P(CheckIfDfsStringsArePalindromesTest, SelfAuthoredRootWithLeaves) {
  // 0 with children 1('b'), 2('a'), s[0]='a' -> "baa" not palindrome.
  std::vector<int> parent = {-1, 0, 0};
  std::string s = "aba";
  std::vector<bool> expected = {false, true, true};
  EXPECT_EQ(solution.findAnswer(parent, s), expected);
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfDfsStringsArePalindromesTestInstance,
    CheckIfDfsStringsArePalindromesTest,
    ::testing::ValuesIn(CheckIfDfsStringsArePalindromesSolution().getStrategyNames()));

}  // namespace problem_3327
}  // namespace leetcode
