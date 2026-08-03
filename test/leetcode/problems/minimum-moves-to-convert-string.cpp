#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-moves-to-convert-string.h"

namespace leetcode::problem_2027 {

using MinimumMovesToConvertStringTest =
    ::testing::TestWithParam<std::string>;

class MinimumMovesToConvertStringFixture
    : public MinimumMovesToConvertStringTest {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumMovesToConvertStringSolution solution;
};

TEST_P(MinimumMovesToConvertStringFixture, Example1) {
  EXPECT_EQ(solution.minimumMoves("XXX"), 1);
}

TEST_P(MinimumMovesToConvertStringFixture, Example2) {
  EXPECT_EQ(solution.minimumMoves("XXOX"), 2);
}

TEST_P(MinimumMovesToConvertStringFixture, Example3) {
  EXPECT_EQ(solution.minimumMoves("OOOO"), 0);
}

TEST_P(MinimumMovesToConvertStringFixture, SelfAuthored_AllXMultiples) {
  EXPECT_EQ(solution.minimumMoves("XXXXXX"), 2);
}

TEST_P(MinimumMovesToConvertStringFixture, SelfAuthored_XOOX) {
  EXPECT_EQ(solution.minimumMoves("XOOX"), 2);
}

TEST_P(MinimumMovesToConvertStringFixture, SelfAuthored_OXOO) {
  EXPECT_EQ(solution.minimumMoves("OXOO"), 1);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumMovesToConvertStringParam,
    MinimumMovesToConvertStringFixture,
    ::testing::ValuesIn(MinimumMovesToConvertStringSolution().getStrategyNames()));

}  // namespace leetcode::problem_2027
