#include <gtest/gtest.h>

#include "leetcode/problems/race-car.h"

using namespace leetcode::problem_818;

class RaceCarTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  RaceCarSolution solution;
};

TEST_P(RaceCarTest, Examples) {
  EXPECT_EQ(solution.racecar(3), 2);
  EXPECT_EQ(solution.racecar(6), 5);
}

TEST_P(RaceCarTest, SelfAuthored) {
  // target = 1: just one 'A'
  EXPECT_EQ(solution.racecar(1), 1);
  // target = 2: minimal is 4 (e.g., "ARRA")
  EXPECT_EQ(solution.racecar(2), 4);
  // target = 4: known to be 5 ("AARRA")
  EXPECT_EQ(solution.racecar(4), 5);
  // target = 5: known to be 7
  EXPECT_EQ(solution.racecar(5), 7);
  // target = 7: 2^3 - 1 = 7, should be 3 ("AAA")
  EXPECT_EQ(solution.racecar(7), 3);
  // target = 8: k=4 overshoots to 15, but k=3 with R,R,A is shorter: "AAARRA" = 6
  EXPECT_EQ(solution.racecar(8), 6);
}

INSTANTIATE_TEST_SUITE_P(RaceCar, RaceCarTest,
                         ::testing::ValuesIn(RaceCarSolution().getStrategyNames()));
