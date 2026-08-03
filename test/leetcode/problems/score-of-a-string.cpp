#include <gtest/gtest.h>

#include "leetcode/problems/score-of-a-string.h"

using namespace leetcode::problem_3110;

class ScoreOfAStringTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  ScoreOfAStringSolution solution;
};

TEST_P(ScoreOfAStringTest, OfficialExamples) {
  EXPECT_EQ(solution.scoreOfString("hello"), 13);
  EXPECT_EQ(solution.scoreOfString("zaz"), 50);
}

TEST_P(ScoreOfAStringTest, SelfAuthoredCases) {
  EXPECT_EQ(solution.scoreOfString("aa"), 0);
  EXPECT_EQ(solution.scoreOfString("ab"), 1);
  EXPECT_EQ(solution.scoreOfString("abc"), 2);
}

INSTANTIATE_TEST_SUITE_P(Strategies, ScoreOfAStringTest,
                         testing::ValuesIn(ScoreOfAStringSolution().getStrategyNames()));
