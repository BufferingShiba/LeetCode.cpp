#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/network-recovery-pathways.h"

namespace leetcode {
namespace problem_3620 {
namespace {

class NetworkRecoveryPathwaysTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NetworkRecoveryPathwaysSolution solution;
};

TEST_P(NetworkRecoveryPathwaysTest, Example1) {
  std::vector<std::vector<int>> edges = {{0, 1, 5}, {1, 3, 10}, {0, 2, 3}, {2, 3, 4}};
  std::vector<bool> online = {true, true, true, true};
  long long k = 10;
  EXPECT_EQ(solution.getSolution()(edges, online, k), 3);
}

TEST_P(NetworkRecoveryPathwaysTest, Example2) {
  std::vector<std::vector<int>> edges = {
      {0, 1, 7}, {1, 4, 5}, {0, 2, 6}, {2, 3, 6}, {3, 4, 2}, {2, 4, 6}};
  std::vector<bool> online = {true, true, true, false, true};
  long long k = 12;
  EXPECT_EQ(solution.getSolution()(edges, online, k), 6);
}

TEST_P(NetworkRecoveryPathwaysTest, SelfAuthoredNoValidPath) {
  // Node 1 (intermediate) is offline and it's the only way to reach n-1.
  std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 2, 1}};
  std::vector<bool> online = {true, false, true};
  long long k = 100;
  EXPECT_EQ(solution.getSolution()(edges, online, k), -1);
}

TEST_P(NetworkRecoveryPathwaysTest, SelfAuthoredSingleEdgeExactK) {
  std::vector<std::vector<int>> edges = {{0, 1, 7}};
  std::vector<bool> online = {true, true};
  long long k = 7;
  EXPECT_EQ(solution.getSolution()(edges, online, k), 7);
}

TEST_P(NetworkRecoveryPathwaysTest, SelfAuthoredCostExceedsK) {
  std::vector<std::vector<int>> edges = {{0, 1, 10}};
  std::vector<bool> online = {true, true};
  long long k = 5;
  EXPECT_EQ(solution.getSolution()(edges, online, k), -1);
}

TEST_P(NetworkRecoveryPathwaysTest, SelfAuthoredNoEdges) {
  std::vector<std::vector<int>> edges = {};
  std::vector<bool> online = {true, true};
  long long k = 0;
  EXPECT_EQ(solution.getSolution()(edges, online, k), -1);
}

TEST_P(NetworkRecoveryPathwaysTest, SelfAuthoredUnreachablePredecessor) {
  // An unreachable node also points to node 2. It must not block the reachable
  // path 0 -> 2 -> 3 in the filtered DAG's topological traversal.
  std::vector<std::vector<int>> edges = {{0, 2, 1}, {1, 2, 1}, {2, 3, 1}};
  std::vector<bool> online = {true, true, true, true};
  long long k = 2;
  EXPECT_EQ(solution.getSolution()(edges, online, k), 1);
}

TEST_P(NetworkRecoveryPathwaysTest, SelfAuthoredOfflineSource) {
  // Edges leaving an offline intermediate node must not affect path validity or
  // the filtered graph's topological order.
  std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 3, 1}, {0, 2, 2}, {2, 3, 2}};
  std::vector<bool> online = {true, false, true, true};
  long long k = 4;
  EXPECT_EQ(solution.getSolution()(edges, online, k), 2);
}

INSTANTIATE_TEST_SUITE_P(
    NetworkRecoveryPathwaysTestSuite, NetworkRecoveryPathwaysTest,
    ::testing::ValuesIn(NetworkRecoveryPathwaysSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3620
}  // namespace leetcode
