#include <gtest/gtest.h>

#include "leetcode/problems/self-crossing.h"

using namespace leetcode::problem_335;

class SelfCrossingTest : public ::testing::TestWithParam<std::string> {
 protected:
  SelfCrossingSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(SelfCrossingTest, Example1) {
  std::vector<int> distance = {2, 1, 1, 2};
  EXPECT_TRUE(solution.isSelfCrossing(distance));
}

TEST_P(SelfCrossingTest, Example2) {
  std::vector<int> distance = {1, 2, 3, 4};
  EXPECT_FALSE(solution.isSelfCrossing(distance));
}

TEST_P(SelfCrossingTest, Example3) {
  std::vector<int> distance = {1, 1, 1, 2, 1};
  EXPECT_TRUE(solution.isSelfCrossing(distance));
}

TEST_P(SelfCrossingTest, SelfAuthoredLessThanFourEdges) {
  std::vector<int> d1 = {1};
  EXPECT_FALSE(solution.isSelfCrossing(d1));
  std::vector<int> d2 = {1, 1};
  EXPECT_FALSE(solution.isSelfCrossing(d2));
  std::vector<int> d3 = {1, 1, 1};
  EXPECT_FALSE(solution.isSelfCrossing(d3));
}

TEST_P(SelfCrossingTest, SelfAuthoredCase2Overlap) {
  std::vector<int> distance = {1, 1, 2, 1, 1};
  EXPECT_TRUE(solution.isSelfCrossing(distance));
}

TEST_P(SelfCrossingTest, SelfAuthoredSpiralExpandingNoCross) {
  std::vector<int> distance = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_FALSE(solution.isSelfCrossing(distance));
}

INSTANTIATE_TEST_SUITE_P(Strategies, SelfCrossingTest,
                         ::testing::ValuesIn(
                             SelfCrossingSolution().getStrategyNames()));
