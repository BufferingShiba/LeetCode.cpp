#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/largest-palindromic-number.h"

namespace leetcode {
namespace problem_2384 {

class LargestPalindromicNumberTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LargestPalindromicNumberSolution solution;
};

TEST_P(LargestPalindromicNumberTest, Example1) {
  EXPECT_EQ(solution.largestPalindromic("444947137"), "7449447");
}

TEST_P(LargestPalindromicNumberTest, Example2) {
  EXPECT_EQ(solution.largestPalindromic("00009"), "9");
}

TEST_P(LargestPalindromicNumberTest, SelfAuthoredAllZerosSingleDigit) {
  EXPECT_EQ(solution.largestPalindromic("0"), "0");
}

TEST_P(LargestPalindromicNumberTest, SelfAuthoredSingleNonZeroDigit) {
  EXPECT_EQ(solution.largestPalindromic("5"), "5");
}

TEST_P(LargestPalindromicNumberTest, SelfAuthoredAllSameEven) {
  EXPECT_EQ(solution.largestPalindromic("2222"), "2222");
}

TEST_P(LargestPalindromicNumberTest, SelfAuthoredLeadingZeroHandle) {
  EXPECT_EQ(solution.largestPalindromic("0098"), "9");
}

TEST_P(LargestPalindromicNumberTest, SelfAuthoredMixedIncludesZeroMiddle) {
  // digits: 1,1,2,2,3,4,4 -> 4213124 (largest)
  EXPECT_EQ(solution.largestPalindromic("1122344"), "4213124");
}

INSTANTIATE_TEST_SUITE_P(
    LargestPalindromicNumberTestCases, LargestPalindromicNumberTest,
    ::testing::ValuesIn(LargestPalindromicNumberSolution().getStrategyNames()));

}  // namespace problem_2384
}  // namespace leetcode
