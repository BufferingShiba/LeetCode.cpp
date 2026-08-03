#include "leetcode/problems/maximum-points-activated-with-one-addition.h"

#include <gtest/gtest.h>

// struct for holding test data
struct MaxActivatedTestCase {
  std::vector<std::vector<int>> points;
  int expected;
};

class MaximumPointsActivatedWithOneAdditionTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  leetcode::problem_3873::MaximumPointsActivatedWithOneAdditionSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MaximumPointsActivatedWithOneAdditionTest, OfficialExamples) {
  std::vector<MaxActivatedTestCase> cases = {
      {{{1, 1}, {1, 2}, {2, 2}}, 4},
      {{{2, 2}, {1, 1}, {3, 3}}, 3},
      {{{2, 3}, {2, 2}, {1, 1}, {4, 5}}, 4},
  };

  for (auto& tc : cases) {
    auto points_copy = tc.points;
    EXPECT_EQ(solution.maxActivated(points_copy), tc.expected);
  }
}

TEST_P(MaximumPointsActivatedWithOneAdditionTest, SinglePoint) {
  std::vector<MaxActivatedTestCase> cases = {
      {{{5, 7}}, 2},
      {{{-1000000000, 1000000000}}, 2},
  };

  for (auto& tc : cases) {
    auto points_copy = tc.points;
    EXPECT_EQ(solution.maxActivated(points_copy), tc.expected);
  }
}

TEST_P(MaximumPointsActivatedWithOneAdditionTest, TwoIndependentClusters) {
  std::vector<MaxActivatedTestCase> cases = {
      // Two clusters each of size 2, plus one isolated => max = 2+2+1
      {{{0, 0}, {0, 1}, {5, 5}, {5, 6}, {9, 9}}, 5},
  };

  for (auto& tc : cases) {
    auto points_copy = tc.points;
    EXPECT_EQ(solution.maxActivated(points_copy), tc.expected);
  }
}

INSTANTIATE_TEST_SUITE_P(
    MaximumPointsActivatedWithOneAdditionTests,
    MaximumPointsActivatedWithOneAdditionTest,
    ::testing::ValuesIn(
        leetcode::problem_3873::MaximumPointsActivatedWithOneAdditionSolution()
            .getStrategyNames()));
