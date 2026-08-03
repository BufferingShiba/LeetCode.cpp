#include <gtest/gtest.h>

#include "leetcode/problems/minimum-time-to-reach-target-with-limited-power.h"

using namespace leetcode::problem_3977;

class MinimumTimeToReachTargetWithLimitedPowerTest : public testing::TestWithParam<std::string> {
 protected:
  MinimumTimeToReachTargetWithLimitedPowerSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MinimumTimeToReachTargetWithLimitedPowerTest, Example1) {
  int n = 5;
  std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 4, 1}, {0, 2, 1}, {2, 3, 1}, {3, 4, 1}};
  int power = 4;
  std::vector<int> cost = {2, 3, 1, 1, 1};
  int source = 0, target = 4;
  auto result = solution.minTimeMaxPower(n, edges, power, cost, source, target);
  EXPECT_EQ(result, (std::vector<long long>{3, 0}));
}

TEST_P(MinimumTimeToReachTargetWithLimitedPowerTest, Example2) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1, 2}, {1, 2, 2}, {2, 0, 2}};
  int power = 3;
  std::vector<int> cost = {1, 1, 1};
  int source = 1, target = 1;
  auto result = solution.minTimeMaxPower(n, edges, power, cost, source, target);
  EXPECT_EQ(result, (std::vector<long long>{0, 3}));
}

TEST_P(MinimumTimeToReachTargetWithLimitedPowerTest, Example3) {
  int n = 4;
  std::vector<std::vector<int>> edges = {{0, 1, 3}, {2, 3, 4}};
  int power = 3;
  std::vector<int> cost = {1, 1, 1, 1};
  int source = 0, target = 3;
  auto result = solution.minTimeMaxPower(n, edges, power, cost, source, target);
  EXPECT_EQ(result, (std::vector<long long>{-1, -1}));
}

TEST_P(MinimumTimeToReachTargetWithLimitedPowerTest, SelfAuthoredSingleNodeSourceEqualsTarget) {
  int n = 1;
  std::vector<std::vector<int>> edges = {};
  int power = 5;
  std::vector<int> cost = {1};
  int source = 0, target = 0;
  auto result = solution.minTimeMaxPower(n, edges, power, cost, source, target);
  EXPECT_EQ(result, (std::vector<long long>{0, 5}));
}

TEST_P(MinimumTimeToReachTargetWithLimitedPowerTest, SelfAuthoredTwoPathsSameTimeDifferentPower) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1, 5}, {1, 2, 3}, {0, 2, 8}};
  int power = 10;
  std::vector<int> cost = {3, 1, 1};
  int source = 0, target = 2;
  auto result = solution.minTimeMaxPower(n, edges, power, cost, source, target);
  EXPECT_EQ(result, (std::vector<long long>{8, 7}));
}

TEST_P(MinimumTimeToReachTargetWithLimitedPowerTest, SelfAuthoredNotEnoughPowerToLeaveSource) {
  int n = 2;
  std::vector<std::vector<int>> edges = {{0, 1, 10}};
  int power = 2;
  std::vector<int> cost = {5, 1};
  int source = 0, target = 1;
  auto result = solution.minTimeMaxPower(n, edges, power, cost, source, target);
  EXPECT_EQ(result, (std::vector<long long>{-1, -1}));
}

INSTANTIATE_TEST_SUITE_P(Strategies, MinimumTimeToReachTargetWithLimitedPowerTest,
                         testing::ValuesIn(
                             MinimumTimeToReachTargetWithLimitedPowerSolution().getStrategyNames()));
