#include <gtest/gtest.h>

#include "leetcode/problems/cheapest-flights-within-k-stops.h"

namespace leetcode::problem_787 {

class CheapestFlightsWithinKStopsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  CheapestFlightsWithinKStopsSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(CheapestFlightsWithinKStopsTest, Example1) {
  int n = 4;
  std::vector<std::vector<int>> flights = {
      {0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
  int src = 0, dst = 3, k = 1;
  EXPECT_EQ(solution.findCheapestPrice(n, flights, src, dst, k), 700);
}

TEST_P(CheapestFlightsWithinKStopsTest, Example2) {
  int n = 3;
  std::vector<std::vector<int>> flights = {
      {0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  int src = 0, dst = 2, k = 1;
  EXPECT_EQ(solution.findCheapestPrice(n, flights, src, dst, k), 200);
}

TEST_P(CheapestFlightsWithinKStopsTest, Example3) {
  int n = 3;
  std::vector<std::vector<int>> flights = {
      {0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  int src = 0, dst = 2, k = 0;
  EXPECT_EQ(solution.findCheapestPrice(n, flights, src, dst, k), 500);
}

INSTANTIATE_TEST_SUITE_P(
    CheapestFlightsWithinKStops,
    CheapestFlightsWithinKStopsTest,
    ::testing::ValuesIn(
        CheapestFlightsWithinKStopsSolution().getStrategyNames()));

}  // namespace leetcode::problem_787
