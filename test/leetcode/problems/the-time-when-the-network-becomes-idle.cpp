#include <gtest/gtest.h>

#include "leetcode/problems/the-time-when-the-network-becomes-idle.h"

namespace leetcode::problem_2039 {

class TheTimeWhenTheNetworkBecomesIdleTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  TheTimeWhenTheNetworkBecomesIdleSolution solution_;
};

TEST_P(TheTimeWhenTheNetworkBecomesIdleTest, Example1) {
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}};
  std::vector<int> patience = {0, 2, 1};
  EXPECT_EQ(solution_.networkBecomesIdle(edges, patience), 8);
}

TEST_P(TheTimeWhenTheNetworkBecomesIdleTest, Example2) {
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};
  std::vector<int> patience = {0, 10, 10};
  EXPECT_EQ(solution_.networkBecomesIdle(edges, patience), 3);
}

TEST_P(TheTimeWhenTheNetworkBecomesIdleTest, SelfAuthoredSingleDataServer) {
  std::vector<std::vector<int>> edges = {{0, 1}};
  std::vector<int> patience = {0, 2};
  EXPECT_EQ(solution_.networkBecomesIdle(edges, patience), 3);
}

TEST_P(TheTimeWhenTheNetworkBecomesIdleTest, SelfAuthoredChainLarger) {
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
  std::vector<int> patience = {0, 1, 1, 1};
  // d=1:p1, lastSend=floor(1/1)*1=1, reply=1+2=3
  // d=2:p1, round=4, lastSend=3, reply=7
  // d=3:p1, round=6, lastSend=5, reply=11 -> ans 12
  EXPECT_EQ(solution_.networkBecomesIdle(edges, patience), 12);
}

INSTANTIATE_TEST_SUITE_P(
    TheTimeWhenTheNetworkBecomesIdleTests,
    TheTimeWhenTheNetworkBecomesIdleTest,
    ::testing::ValuesIn(
        TheTimeWhenTheNetworkBecomesIdleSolution().getStrategyNames()));

}  // namespace leetcode::problem_2039
