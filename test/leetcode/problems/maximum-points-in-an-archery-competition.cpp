#include <gtest/gtest.h>

#include "leetcode/problems/maximum-points-in-an-archery-competition.h"

namespace leetcode::problem_2212 {

class MaximumPointsInAnArcheryCompetitionTest
    : public testing::TestWithParam<std::string> {
 protected:
  MaximumPointsInAnArcheryCompetitionSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MaximumPointsInAnArcheryCompetitionTest, Example1) {
  int numArrows = 9;
  std::vector<int> aliceArrows = {1, 1, 0, 1, 0, 0, 2, 1, 0, 1, 2, 0};
  auto bobArrows = solution.maximumBobPoints(numArrows, aliceArrows);

  int sum = 0;
  for (int x : bobArrows) sum += x;
  EXPECT_EQ(sum, numArrows);

  int bobScore = 0;
  for (int k = 0; k < 12; ++k) {
    if (bobArrows[k] > aliceArrows[k]) {
      bobScore += k;
    }
  }
  EXPECT_EQ(bobScore, 47);
}

TEST_P(MaximumPointsInAnArcheryCompetitionTest, Example2) {
  int numArrows = 3;
  std::vector<int> aliceArrows = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2};
  auto bobArrows = solution.maximumBobPoints(numArrows, aliceArrows);

  int sum = 0;
  for (int x : bobArrows) sum += x;
  EXPECT_EQ(sum, numArrows);

  int bobScore = 0;
  for (int k = 0; k < 12; ++k) {
    if (bobArrows[k] > aliceArrows[k]) {
      bobScore += k;
    }
  }
  EXPECT_EQ(bobScore, 27);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MaximumPointsInAnArcheryCompetitionTest,
    testing::ValuesIn(
        MaximumPointsInAnArcheryCompetitionSolution().getStrategyNames()));

}  // namespace leetcode::problem_2212
