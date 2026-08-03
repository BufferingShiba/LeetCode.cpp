#include <gtest/gtest.h>
#include "leetcode/problems/find-minimum-log-transportation-cost.h"

namespace leetcode {
namespace problem_3560 {
namespace {

class FindMinimumLogTransportationCostTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  FindMinimumLogTransportationCostSolution solution;
};

TEST_P(FindMinimumLogTransportationCostTest, Example1) {
  EXPECT_EQ(5, solution.minCuttingCost(6, 5, 5));
}

TEST_P(FindMinimumLogTransportationCostTest, Example2) {
  EXPECT_EQ(0, solution.minCuttingCost(4, 4, 6));
}

TEST_P(FindMinimumLogTransportationCostTest, NoCut) {
  EXPECT_EQ(0, solution.minCuttingCost(3, 3, 5));
}

TEST_P(FindMinimumLogTransportationCostTest, OnlyNTooLong) {
  // n=8>k=5, m=5<=k => cut n into 5 and 3, cost 5*3=15
  EXPECT_EQ(15, solution.minCuttingCost(8, 5, 5));
}

TEST_P(FindMinimumLogTransportationCostTest, OnlyMTooLong) {
  // m=7>k=4, n=3<=k => cut m into 4 and 3, cost 4*3=12
  EXPECT_EQ(12, solution.minCuttingCost(3, 7, 4));
}

INSTANTIATE_TEST_SUITE_P(
    FindMinimumLogTransportationCostTestSuite,
    FindMinimumLogTransportationCostTest,
    ::testing::ValuesIn(
        FindMinimumLogTransportationCostSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3560
}  // namespace leetcode
