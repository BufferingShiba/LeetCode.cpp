#include <gtest/gtest.h>

#include "leetcode/problems/length-of-the-longest-alphabetical-continuous-substring.h"

namespace leetcode {
namespace problem_2414 {

class LengthOfTheLongestAlphabeticalContinuousSubstringTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  LengthOfTheLongestAlphabeticalContinuousSubstringSolution solution_;
};

TEST_P(LengthOfTheLongestAlphabeticalContinuousSubstringTest, Examples) {
  // Example 1
  EXPECT_EQ(solution_.longestContinuousSubstring("abacaba"), 2);
  // Example 2
  EXPECT_EQ(solution_.longestContinuousSubstring("abcde"), 5);
}

TEST_P(LengthOfTheLongestAlphabeticalContinuousSubstringTest, SelfAuthored) {
  // Single character
  EXPECT_EQ(solution_.longestContinuousSubstring("a"), 1);
  // No consecutive letters
  EXPECT_EQ(solution_.longestContinuousSubstring("aceg"), 1);
  // Multiple segments: "abc" length 3, "xyz" length 3
  EXPECT_EQ(solution_.longestContinuousSubstring("abcxyz"), 3);
  // Wrap-around 'za' is NOT continuous
  EXPECT_EQ(solution_.longestContinuousSubstring("za"), 1);
  // All same letter
  EXPECT_EQ(solution_.longestContinuousSubstring("zzzz"), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, LengthOfTheLongestAlphabeticalContinuousSubstringTest,
    testing::ValuesIn(LengthOfTheLongestAlphabeticalContinuousSubstringSolution()
                          .getStrategyNames()));

}  // namespace problem_2414
}  // namespace leetcode
