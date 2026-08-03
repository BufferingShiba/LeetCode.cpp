#include <gtest/gtest.h>

#include "leetcode/problems/bus-routes.h"

using namespace leetcode::problem_815;

class BusRoutesTest : public ::testing::TestWithParam<std::string> {
 protected:
  BusRoutesSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(BusRoutesTest, Example1) {
  std::vector<std::vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
  EXPECT_EQ(solution.numBusesToDestination(routes, 1, 6), 2);
}

TEST_P(BusRoutesTest, Example2) {
  std::vector<std::vector<int>> routes = {
      {7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}};
  EXPECT_EQ(solution.numBusesToDestination(routes, 15, 12), -1);
}

TEST_P(BusRoutesTest, SelfAuthoredSameSourceAndTarget) {
  std::vector<std::vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
  EXPECT_EQ(solution.numBusesToDestination(routes, 1, 1), 0);
}

TEST_P(BusRoutesTest, SelfAuthoredSourceNotOnAnyRoute) {
  std::vector<std::vector<int>> routes = {{1, 2, 3}, {4, 5, 6}};
  EXPECT_EQ(solution.numBusesToDestination(routes, 10, 1), -1);
}

TEST_P(BusRoutesTest, SelfAuthoredSingleRouteDirect) {
  std::vector<std::vector<int>> routes = {{1, 2, 3, 4, 5}};
  EXPECT_EQ(solution.numBusesToDestination(routes, 1, 5), 1);
}

INSTANTIATE_TEST_SUITE_P(Strategies, BusRoutesTest,
                         ::testing::ValuesIn(BusRoutesSolution().getStrategyNames()));
