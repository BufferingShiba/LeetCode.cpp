#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/number-of-operations-to-make-network-connected.h"

using namespace leetcode::problem_1319;

class NumberOfOperationsToMakeNetworkConnectedTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  NumberOfOperationsToMakeNetworkConnectedSolution solution_;
};

TEST_P(NumberOfOperationsToMakeNetworkConnectedTest, Example1) {
  int n = 4;
  std::vector<std::vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
  EXPECT_EQ(solution_.makeConnected(n, connections), 1);
}

TEST_P(NumberOfOperationsToMakeNetworkConnectedTest, Example2) {
  int n = 6;
  std::vector<std::vector<int>> connections = {
      {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
  EXPECT_EQ(solution_.makeConnected(n, connections), 2);
}

TEST_P(NumberOfOperationsToMakeNetworkConnectedTest, Example3) {
  int n = 6;
  std::vector<std::vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
  EXPECT_EQ(solution_.makeConnected(n, connections), -1);
}

TEST_P(NumberOfOperationsToMakeNetworkConnectedTest, SelfAuthoredSingleComputer) {
  int n = 1;
  std::vector<std::vector<int>> connections = {};
  EXPECT_EQ(solution_.makeConnected(n, connections), 0);
}

TEST_P(NumberOfOperationsToMakeNetworkConnectedTest, SelfAuthoredAlreadyConnected) {
  int n = 3;
  std::vector<std::vector<int>> connections = {{0, 1}, {1, 2}};
  EXPECT_EQ(solution_.makeConnected(n, connections), 0);
}

TEST_P(NumberOfOperationsToMakeNetworkConnectedTest, SelfAuthoredJustEnoughCables) {
  int n = 5;
  std::vector<std::vector<int>> connections = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
  EXPECT_EQ(solution_.makeConnected(n, connections), 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, NumberOfOperationsToMakeNetworkConnectedTest,
    testing::ValuesIn(
        NumberOfOperationsToMakeNetworkConnectedSolution().getStrategyNames()));
