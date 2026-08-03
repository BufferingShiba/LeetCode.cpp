#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-product-of-the-length-of-two-palindromic-subsequences.h"

namespace leetcode {
namespace problem_2002 {

class MaximumProductOfTheLengthOfTwoPalindromicSubsequencesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumProductOfTheLengthOfTwoPalindromicSubsequencesSolution solution;
};

TEST_P(MaximumProductOfTheLengthOfTwoPalindromicSubsequencesTest, Example1) {
  EXPECT_EQ(solution.maxProduct("leetcodecom"), 9);
}

TEST_P(MaximumProductOfTheLengthOfTwoPalindromicSubsequencesTest, Example2) {
  EXPECT_EQ(solution.maxProduct("bb"), 1);
}

TEST_P(MaximumProductOfTheLengthOfTwoPalindromicSubsequencesTest, Example3) {
  EXPECT_EQ(solution.maxProduct("accbcaxxcxx"), 25);
}

TEST_P(MaximumProductOfTheLengthOfTwoPalindromicSubsequencesTest, SelfAuthoredAllSameChars) {
  EXPECT_EQ(solution.maxProduct("aaa"), 2);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumProductOfTheLengthOfTwoPalindromicSubsequencesTest,
    MaximumProductOfTheLengthOfTwoPalindromicSubsequencesTest,
    ::testing::ValuesIn(
        MaximumProductOfTheLengthOfTwoPalindromicSubsequencesSolution()
            .getStrategyNames()));

}  // namespace problem_2002
}  // namespace leetcode
