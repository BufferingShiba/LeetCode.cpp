#include <gtest/gtest.h>
#include "leetcode/problems/minimum-additions-to-make-valid-string.h"

namespace leetcode::problem_2645 {

class MinimumAdditionsToMakeValidStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  MinimumAdditionsToMakeValidStringSolution solution_;
};

TEST_P(MinimumAdditionsToMakeValidStringTest, Example1) {
  EXPECT_EQ(solution_.addMinimum("b"), 2);
}

TEST_P(MinimumAdditionsToMakeValidStringTest, Example2) {
  EXPECT_EQ(solution_.addMinimum("aaa"), 6);
}

TEST_P(MinimumAdditionsToMakeValidStringTest, Example3) {
  EXPECT_EQ(solution_.addMinimum("abc"), 0);
}

TEST_P(MinimumAdditionsToMakeValidStringTest, SelfAuthored) {
  EXPECT_EQ(solution_.addMinimum("a"), 2);
  EXPECT_EQ(solution_.addMinimum("c"), 2);
  EXPECT_EQ(solution_.addMinimum("ab"), 1);
  EXPECT_EQ(solution_.addMinimum("bc"), 1);
  EXPECT_EQ(solution_.addMinimum("ac"), 1);
  EXPECT_EQ(solution_.addMinimum("abcabc"), 0);
  EXPECT_EQ(solution_.addMinimum("abca"), 2);
  EXPECT_EQ(solution_.addMinimum("cb"), 4);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MinimumAdditionsToMakeValidStringTest,
    ::testing::ValuesIn(
        MinimumAdditionsToMakeValidStringSolution().getStrategyNames()));

}  // namespace leetcode::problem_2645
