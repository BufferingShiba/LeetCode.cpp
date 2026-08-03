#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/removing-stars-from-a-string.h"

namespace leetcode::problem_2390 {

class RemovingStarsFromAStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  RemovingStarsFromAStringSolution solution_;
};

TEST_P(RemovingStarsFromAStringTest, OfficialExamples) {
  EXPECT_EQ(solution_.removeStars("leet**cod*e"), "lecoe");
  EXPECT_EQ(solution_.removeStars("erase*****"), "");
}

TEST_P(RemovingStarsFromAStringTest, SelfAuthored) {
  // No stars at all
  EXPECT_EQ(solution_.removeStars("abc"), "abc");
  // All characters removed
  EXPECT_EQ(solution_.removeStars("a*b*c*"), "");
  // Stars at the beginning cannot happen per constraints, but just in case
  // it's guaranteed that operations are always possible, so skipped.
  // Alternating patterns
  EXPECT_EQ(solution_.removeStars("ab*cd*e"), "ace");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    RemovingStarsFromAStringTest,
    ::testing::ValuesIn(
        RemovingStarsFromAStringSolution().getStrategyNames()));

}  // namespace leetcode::problem_2390
