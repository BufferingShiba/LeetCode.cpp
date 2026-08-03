#include <gtest/gtest.h>

#include "leetcode/problems/shift-distance-between-two-strings.h"

using namespace leetcode::problem_3361;

class ShiftDistanceBetweenTwoStringsTest : public ::testing::TestWithParam<std::string> {
 protected:
  ShiftDistanceBetweenTwoStringsSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(ShiftDistanceBetweenTwoStringsTest, Example1) {
  std::string s = "abab";
  std::string t = "baba";
  std::vector<int> nextCost(26, 0);
  std::vector<int> previousCost(26, 0);
  nextCost[0] = 100;
  previousCost[0] = 1;
  previousCost[1] = 100;
  EXPECT_EQ(solution.shiftDistance(s, t, nextCost, previousCost), 2);
}

TEST_P(ShiftDistanceBetweenTwoStringsTest, Example2) {
  std::string s = "leet";
  std::string t = "code";
  std::vector<int> nextCost(26, 1);
  std::vector<int> previousCost(26, 1);
  EXPECT_EQ(solution.shiftDistance(s, t, nextCost, previousCost), 31);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    ShiftDistanceBetweenTwoStringsTest,
    ::testing::ValuesIn(ShiftDistanceBetweenTwoStringsSolution().getStrategyNames()));
