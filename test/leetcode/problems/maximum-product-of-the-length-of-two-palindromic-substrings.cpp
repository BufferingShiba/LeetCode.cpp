#include "leetcode/problems/maximum-product-of-the-length-of-two-palindromic-substrings.h"
#include <gtest/gtest.h>
#include <string>

namespace leetcode {
namespace problem_1960 {

class MaximumProductOfTheLengthOfTwoPalindromicSubstringsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumProductOfTheLengthOfTwoPalindromicSubstringsSolution solution;
};

TEST_P(MaximumProductOfTheLengthOfTwoPalindromicSubstringsTest, Example1) {
  EXPECT_EQ(9, solution.maxProduct("ababbb"));
}

TEST_P(MaximumProductOfTheLengthOfTwoPalindromicSubstringsTest, Example2) {
  EXPECT_EQ(9, solution.maxProduct("zaaaxbbby"));
}

TEST_P(MaximumProductOfTheLengthOfTwoPalindromicSubstringsTest,
      SelfAuthoredAllSameChar) {
  EXPECT_EQ(3, solution.maxProduct("aaaaa"));
}

TEST_P(MaximumProductOfTheLengthOfTwoPalindromicSubstringsTest,
      SelfAuthoredTwoChar) {
  EXPECT_EQ(1, solution.maxProduct("ab"));
  EXPECT_EQ(1, solution.maxProduct("aa"));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumProductOfTheLengthOfTwoPalindromicSubstringsTestSuite,
    MaximumProductOfTheLengthOfTwoPalindromicSubstringsTest,
    ::testing::ValuesIn(
        MaximumProductOfTheLengthOfTwoPalindromicSubstringsSolution()
            .getStrategyNames()));

}  // namespace problem_1960
}  // namespace leetcode
