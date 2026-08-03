#include <gtest/gtest.h>

#include "leetcode/problems/maximum-profit-of-operating-a-centennial-wheel.h"

namespace leetcode::problem_1599 {

class MaximumProfitOfOperatingACentennialWheelTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumProfitOfOperatingACentennialWheelSolution solution;
};

TEST_P(MaximumProfitOfOperatingACentennialWheelTest, Example1) {
  std::vector<int> customers = {8, 3};
  int boardingCost = 5;
  int runningCost = 6;
  EXPECT_EQ(solution.minOperationsMaxProfit(customers, boardingCost, runningCost), 3);
}

TEST_P(MaximumProfitOfOperatingACentennialWheelTest, Example2) {
  std::vector<int> customers = {10, 9, 6};
  int boardingCost = 6;
  int runningCost = 4;
  EXPECT_EQ(solution.minOperationsMaxProfit(customers, boardingCost, runningCost), 7);
}

TEST_P(MaximumProfitOfOperatingACentennialWheelTest, Example3) {
  std::vector<int> customers = {3, 4, 0, 5, 1};
  int boardingCost = 1;
  int runningCost = 92;
  EXPECT_EQ(solution.minOperationsMaxProfit(customers, boardingCost, runningCost), -1);
}

TEST_P(MaximumProfitOfOperatingACentennialWheelTest, SelfAuthoredNoCustomers) {
  std::vector<int> customers = {0, 0, 0};
  int boardingCost = 10;
  int runningCost = 1;
  EXPECT_EQ(solution.minOperationsMaxProfit(customers, boardingCost, runningCost), -1);
}

TEST_P(MaximumProfitOfOperatingACentennialWheelTest, SelfAuthoredProfitNeverPositive) {
  std::vector<int> customers = {1};
  int boardingCost = 1;
  int runningCost = 100;
  EXPECT_EQ(solution.minOperationsMaxProfit(customers, boardingCost, runningCost), -1);
}

TEST_P(MaximumProfitOfOperatingACentennialWheelTest, SelfAuthoredLargeWaitingQueue) {
  // 50 customers arrive each of 100 rotations → total 5000 customers
  std::vector<int> customers(100, 50);
  int boardingCost = 5;
  int runningCost = 3;
  // Just ensure it doesn't crash and returns a positive rotation count
  int result = solution.minOperationsMaxProfit(customers, boardingCost, runningCost);
  EXPECT_GT(result, 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MaximumProfitOfOperatingACentennialWheelTest,
    testing::ValuesIn(
        MaximumProfitOfOperatingACentennialWheelSolution().getStrategyNames()));

}  // namespace leetcode::problem_1599
