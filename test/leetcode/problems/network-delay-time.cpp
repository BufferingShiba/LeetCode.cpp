#include <gtest/gtest.h>

#include "leetcode/problems/network-delay-time.h"

using namespace leetcode::problem_743;

class NetworkDelayTimeTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  NetworkDelayTimeSolution solution;
};

TEST_P(NetworkDelayTimeTest, Example1) {
  std::vector<std::vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
  int n = 4, k = 2;
  EXPECT_EQ(solution.networkDelayTime(times, n, k), 2);
}

TEST_P(NetworkDelayTimeTest, Example2) {
  std::vector<std::vector<int>> times = {{1, 2, 1}};
  int n = 2, k = 1;
  EXPECT_EQ(solution.networkDelayTime(times, n, k), 1);
}

TEST_P(NetworkDelayTimeTest, Example3) {
  std::vector<std::vector<int>> times = {{1, 2, 1}};
  int n = 2, k = 2;
  EXPECT_EQ(solution.networkDelayTime(times, n, k), -1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    NetworkDelayTimeTest,
    testing::ValuesIn(NetworkDelayTimeSolution().getStrategyNames()));
