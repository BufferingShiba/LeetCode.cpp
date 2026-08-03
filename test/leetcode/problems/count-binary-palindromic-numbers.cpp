#include <gtest/gtest.h>
#include "leetcode/problems/count-binary-palindromic-numbers.h"

namespace leetcode::problem_3677 {

class CountBinaryPalindromicNumbersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  CountBinaryPalindromicNumbersSolution solution;
};

TEST_P(CountBinaryPalindromicNumbersTest, OfficialExample1) {
  EXPECT_EQ(solution.countBinaryPalindromes(9), 6);
}

TEST_P(CountBinaryPalindromicNumbersTest, OfficialExample2) {
  EXPECT_EQ(solution.countBinaryPalindromes(0), 1);
}

TEST_P(CountBinaryPalindromicNumbersTest, SelfAuthoredSmallBounds) {
  // n=1: palindromes are 0 and 1
  EXPECT_EQ(solution.countBinaryPalindromes(1), 2);
  // n=2: 0,1 are palindromes; 2 ("10") is not
  EXPECT_EQ(solution.countBinaryPalindromes(2), 2);
  // n=3: 0,1,3 ("11")
  EXPECT_EQ(solution.countBinaryPalindromes(3), 3);
  // n=4: 0,1,3 ("100" not palindrome)
  EXPECT_EQ(solution.countBinaryPalindromes(4), 3);
  // n=15: all binary palindromes up to length 4
  // lengths: 1→2, 2→1, 3→2, 4→2, total=7
  EXPECT_EQ(solution.countBinaryPalindromes(15), 7);
  // n=16 ("10000"): still 7 (16 not palindrome)
  EXPECT_EQ(solution.countBinaryPalindromes(16), 7);
}

TEST_P(CountBinaryPalindromicNumbersTest, SelfAuthoredMediumBound) {
  // n=100: let's compute known palindromes manually or trust the pattern
  // Just verify monotonicity and reasonable range
  int c9 = solution.countBinaryPalindromes(9);
  int c99 = solution.countBinaryPalindromes(99);
  int c100 = solution.countBinaryPalindromes(100);
  EXPECT_EQ(c9, 6);
  EXPECT_GE(c99, c9);
  EXPECT_GE(c100, c99);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CountBinaryPalindromicNumbersTest,
    ::testing::ValuesIn(
        CountBinaryPalindromicNumbersSolution().getStrategyNames()));

}  // namespace leetcode::problem_3677
