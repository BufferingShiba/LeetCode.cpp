#include <gtest/gtest.h>
#include "leetcode/problems/longest-balanced-substring-ii.h"

namespace leetcode {
namespace problem_3714 {

class LongestBalancedSubstringIiTest
    : public ::testing::TestWithParam<std::string> {
protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  LongestBalancedSubstringIiSolution solution_;
};

// clang-format off
INSTANTIATE_TEST_SUITE_P(
    LongestBalancedSubstringIiStrategies, LongestBalancedSubstringIiTest,
    ::testing::ValuesIn(LongestBalancedSubstringIiSolution().getStrategyNames()));
// clang-format on

TEST_P(LongestBalancedSubstringIiTest, Example1) {
  ASSERT_EQ(solution_.getSolution()(std::string("abbac")), 4);
}

TEST_P(LongestBalancedSubstringIiTest, Example2) {
  ASSERT_EQ(solution_.getSolution()(std::string("aabcc")), 3);
}

TEST_P(LongestBalancedSubstringIiTest, Example3) {
  ASSERT_EQ(solution_.getSolution()(std::string("aba")), 2);
}

TEST_P(LongestBalancedSubstringIiTest, SingleCharacter) {
  ASSERT_EQ(solution_.getSolution()(std::string("a")), 1);
}

TEST_P(LongestBalancedSubstringIiTest, AllSameMulti) {
  // "bbbb" has only one distinct char appearing 4 times -> balanced, len 4.
  ASSERT_EQ(solution_.getSolution()(std::string("bbbb")), 4);
}

TEST_P(LongestBalancedSubstringIiTest, TwoCharBalanced) {
  ASSERT_EQ(solution_.getSolution()(std::string("abab")), 4);
}

TEST_P(LongestBalancedSubstringIiTest, ThreeCharBalanced) {
  ASSERT_EQ(solution_.getSolution()(std::string("abcabc")), 6);
}

TEST_P(LongestBalancedSubstringIiTest, TwoCharMultiple) {
  // "aabb" balanced (a2,b2).
  ASSERT_EQ(solution_.getSolution()(std::string("aabb")), 4);
}

TEST_P(LongestBalancedSubstringIiTest, LongRunSingleChar) {
  ASSERT_EQ(solution_.getSolution()(std::string("aaa")), 3);
}

}  // namespace problem_3714
}  // namespace leetcode
