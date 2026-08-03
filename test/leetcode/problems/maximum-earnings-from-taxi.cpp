#include "leetcode/problems/maximum-earnings-from-taxi.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_2008 {
namespace {

long long runStrategy(const std::string& name, int n, std::vector<std::vector<int>> rides) {
  MaximumEarningsFromTaxiSolution solution;
  solution.setStrategy(name);
  return solution.getSolution()(n, rides);
}

}  // namespace

class MaximumEarningsFromTaxiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumEarningsFromTaxiSolution solution;
};

TEST_P(MaximumEarningsFromTaxiTest, Example1) {
  int n = 5;
  std::vector<std::vector<int>> rides = {{2, 5, 4}, {1, 5, 1}};
  EXPECT_EQ(7, solution.getSolution()(n, rides));
}

TEST_P(MaximumEarningsFromTaxiTest, Example2) {
  int n = 20;
  std::vector<std::vector<int>> rides = {
      {1, 6, 1}, {3, 10, 2}, {10, 12, 3}, {11, 12, 2}, {12, 15, 2}, {13, 18, 1}};
  EXPECT_EQ(20, solution.getSolution()(n, rides));
}

TEST_P(MaximumEarningsFromTaxiTest, SelfAuthoredSingleRide) {
  int n = 5;
  std::vector<std::vector<int>> rides = {{1, 5, 10}};
  EXPECT_EQ(14, solution.getSolution()(n, rides));
}

TEST_P(MaximumEarningsFromTaxiTest, SelfAuthoredNoOverlapAndCombine) {
  int n = 10;
  std::vector<std::vector<int>> rides = {{1, 3, 1}, {3, 8, 2}};
  // ride1 = 3-1+1 = 3, ride2 = 8-3+2 = 7, total = 10
  EXPECT_EQ(10, solution.getSolution()(n, rides));
}

TEST_P(MaximumEarningsFromTaxiTest, SelfAuthoredCannotCombineOverlapping) {
  int n = 10;
  std::vector<std::vector<int>> rides = {{1, 4, 1}, {3, 10, 5}};
  // ride1 = 4, ride2 = 10-3+5 = 12 (overlap, pick one: better is 12)
  EXPECT_EQ(12, solution.getSolution()(n, rides));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumEarningsFromTaxiTestInstance,
    MaximumEarningsFromTaxiTest,
    ::testing::ValuesIn(MaximumEarningsFromTaxiSolution().getStrategyNames()));

}  // namespace problem_2008
}  // namespace leetcode
