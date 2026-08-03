#include <gtest/gtest.h>
#include "leetcode/problems/last-substring-in-lexicographical-order.h"

namespace leetcode::problem_1163 {

class LastSubstringInLexicographicalOrderTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  LastSubstringInLexicographicalOrderSolution solution_;
};

TEST_P(LastSubstringInLexicographicalOrderTest, OfficialExamples) {
  EXPECT_EQ(solution_.lastSubstring("abab"), "bab");
  EXPECT_EQ(solution_.lastSubstring("leetcode"), "tcode");
}

TEST_P(LastSubstringInLexicographicalOrderTest, SelfAuthored) {
  EXPECT_EQ(solution_.lastSubstring("a"), "a");
  EXPECT_EQ(solution_.lastSubstring("zzz"), "zzz");
  EXPECT_EQ(solution_.lastSubstring("cba"), "cba");
  EXPECT_EQ(solution_.lastSubstring("abcz"), "z");
  EXPECT_EQ(solution_.lastSubstring("aa"), "aa");
  EXPECT_EQ(solution_.lastSubstring("ba"), "ba");
}

INSTANTIATE_TEST_SUITE_P(
    LastSubstringInLexicographicalOrder,
    LastSubstringInLexicographicalOrderTest,
    ::testing::ValuesIn(
        LastSubstringInLexicographicalOrderSolution().getStrategyNames()));

}  // namespace leetcode::problem_1163
