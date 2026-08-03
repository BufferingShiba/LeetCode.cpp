#include <gtest/gtest.h>

#include "leetcode/problems/total-distance-traveled.h"

using namespace leetcode::problem_2739;

class TotalDistanceTraveledTest : public ::testing::TestWithParam<std::string> {
 protected:
  TotalDistanceTraveledSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(TotalDistanceTraveledTest, OfficialExamples) {
  EXPECT_EQ(solution.distanceTraveled(5, 10), 60);
  EXPECT_EQ(solution.distanceTraveled(1, 2), 10);
}

TEST_P(TotalDistanceTraveledTest, SelfAuthored) {
  // 9 + 2 transfers → 5+4 + 5+4 + 1 = 110
  EXPECT_EQ(solution.distanceTraveled(9, 2), 110);
  // No additional fuel
  EXPECT_EQ(solution.distanceTraveled(10, 0), 100);
  // Not enough consumption to trigger transfer
  EXPECT_EQ(solution.distanceTraveled(4, 100), 40);
}

INSTANTIATE_TEST_SUITE_P(Strategies, TotalDistanceTraveledTest,
                         ::testing::ValuesIn(
                             TotalDistanceTraveledSolution().getStrategyNames()));
