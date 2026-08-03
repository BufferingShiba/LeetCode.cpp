#include <gtest/gtest.h>

#include "leetcode/problems/find-the-town-judge.h"

using leetcode::problem_997::FindTheTownJudgeSolution;

class FindTheTownJudgeTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  FindTheTownJudgeSolution solution;
};

TEST_P(FindTheTownJudgeTest, Example1) {
  int n = 2;
  std::vector<std::vector<int>> trust = {{1, 2}};
  EXPECT_EQ(2, solution.findJudge(n, trust));
}

TEST_P(FindTheTownJudgeTest, Example2) {
  int n = 3;
  std::vector<std::vector<int>> trust = {{1, 3}, {2, 3}};
  EXPECT_EQ(3, solution.findJudge(n, trust));
}

TEST_P(FindTheTownJudgeTest, Example3) {
  int n = 3;
  std::vector<std::vector<int>> trust = {{1, 3}, {2, 3}, {3, 1}};
  EXPECT_EQ(-1, solution.findJudge(n, trust));
}

TEST_P(FindTheTownJudgeTest, SelfAuthoredSinglePersonNoTrust) {
  int n = 1;
  std::vector<std::vector<int>> trust = {};
  EXPECT_EQ(1, solution.findJudge(n, trust));
}

TEST_P(FindTheTownJudgeTest, SelfAuthoredJudgeTrustsSomeone) {
  int n = 3;
  std::vector<std::vector<int>> trust = {{1, 2}, {2, 3}, {3, 2}};
  EXPECT_EQ(-1, solution.findJudge(n, trust));
}

TEST_P(FindTheTownJudgeTest, SelfAuthoredEmptyTrustLargeN) {
  int n = 4;
  std::vector<std::vector<int>> trust = {};
  EXPECT_EQ(-1, solution.findJudge(n, trust));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheTownJudgeTestCases, FindTheTownJudgeTest,
    ::testing::ValuesIn(FindTheTownJudgeSolution().getStrategyNames()));
