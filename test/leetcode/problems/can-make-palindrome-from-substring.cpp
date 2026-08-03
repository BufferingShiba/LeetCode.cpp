#include <gtest/gtest.h>

#include "leetcode/problems/can-make-palindrome-from-substring.h"

namespace leetcode::problem_1177 {

class CanMakePalindromeFromSubstringTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CanMakePalindromeFromSubstringSolution solution;
};

TEST_P(CanMakePalindromeFromSubstringTest, Example1) {
  std::string s = "abcda";
  std::vector<std::vector<int>> queries = {
      {3, 3, 0}, {1, 2, 0}, {0, 3, 1}, {0, 3, 2}, {0, 4, 1}};
  auto result = solution.canMakePaliQueries(s, queries);
  std::vector<bool> expected = {true, false, false, true, true};
  EXPECT_EQ(result, expected);
}

TEST_P(CanMakePalindromeFromSubstringTest, SelfAuthoredExample2) {
  std::string s = "lyb";
  std::vector<std::vector<int>> queries = {{0, 1, 0}, {2, 2, 1}};
  auto result = solution.canMakePaliQueries(s, queries);
  std::vector<bool> expected = {false, true};
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CanMakePalindromeFromSubstringTest,
    testing::ValuesIn(
        CanMakePalindromeFromSubstringSolution().getStrategyNames()));

}  // namespace leetcode::problem_1177
