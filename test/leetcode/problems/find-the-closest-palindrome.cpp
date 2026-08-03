#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-closest-palindrome.h"

namespace leetcode {
namespace problem_564 {

class FindTheClosestPalindromeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  FindTheClosestPalindromeSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(FindTheClosestPalindromeTest, Example1) {
  EXPECT_EQ(solution.nearestPalindromic("123"), "121");
}

TEST_P(FindTheClosestPalindromeTest, Example2) {
  EXPECT_EQ(solution.nearestPalindromic("1"), "0");
}

TEST_P(FindTheClosestPalindromeTest, SelfAuthoredSingleDigit9) {
  EXPECT_EQ(solution.nearestPalindromic("9"), "8");
}

TEST_P(FindTheClosestPalindromeTest, SelfAuthoredTenToNine) {
  EXPECT_EQ(solution.nearestPalindromic("10"), "9");
}

TEST_P(FindTheClosestPalindromeTest, SelfAuthoredNinetyNine) {
  EXPECT_EQ(solution.nearestPalindromic("99"), "101");
}

TEST_P(FindTheClosestPalindromeTest, SelfAuthoredOneThousand) {
  EXPECT_EQ(solution.nearestPalindromic("1000"), "999");
}

TEST_P(FindTheClosestPalindromeTest, SelfAuthoredOneHundredOne) {
  EXPECT_EQ(solution.nearestPalindromic("101"), "99");
}

TEST_P(FindTheClosestPalindromeTest, SelfAuthoredTiePreferSmaller) {
  EXPECT_EQ(solution.nearestPalindromic("121"), "111");
}

TEST_P(FindTheClosestPalindromeTest, OnlineCounterExample) {
  EXPECT_EQ(solution.nearestPalindromic("1213"), "1221");
}

INSTANTIATE_TEST_SUITE_P(
    FindTheClosestPalindromeTestSuite, FindTheClosestPalindromeTest,
    ::testing::ValuesIn(FindTheClosestPalindromeSolution().getStrategyNames()));

}  // namespace problem_564
}  // namespace leetcode
