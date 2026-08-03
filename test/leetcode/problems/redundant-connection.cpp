#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/redundant-connection.h"

namespace leetcode {
namespace problem_684 {

class RedundantConnectionTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RedundantConnectionSolution solution;
};

TEST_P(RedundantConnectionTest, Example1) {
  std::vector<std::vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
  std::vector<int> expected = {2, 3};
  EXPECT_EQ(solution.findRedundantConnection(edges), expected);
}

TEST_P(RedundantConnectionTest, Example2) {
  std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
  std::vector<int> expected = {1, 4};
  EXPECT_EQ(solution.findRedundantConnection(edges), expected);
}

TEST_P(RedundantConnectionTest, SelfAuthoredLastEdgeRedundant) {
  std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}, {3, 1}};
  std::vector<int> expected = {3, 1};
  EXPECT_EQ(solution.findRedundantConnection(edges), expected);
}

INSTANTIATE_TEST_SUITE_P(
    RedundantConnectionStrategies, RedundantConnectionTest,
    ::testing::ValuesIn(RedundantConnectionSolution().getStrategyNames()));

}  // namespace problem_684
}  // namespace leetcode
