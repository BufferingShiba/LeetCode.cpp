#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/divide-nodes-into-the-maximum-number-of-groups.h"

namespace leetcode::problem_2493 {

class DivideNodesIntoTheMaximumNumberOfGroupsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  DivideNodesIntoTheMaximumNumberOfGroupsSolution solution_;
};

TEST_P(DivideNodesIntoTheMaximumNumberOfGroupsTest, Example1) {
  int n = 6;
  std::vector<std::vector<int>> edges = {
      {1, 2}, {1, 4}, {1, 5}, {2, 6}, {2, 3}, {4, 6}};
  EXPECT_EQ(4, solution_.magnificentSets(n, edges));
}

TEST_P(DivideNodesIntoTheMaximumNumberOfGroupsTest, Example2) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}, {3, 1}};
  EXPECT_EQ(-1, solution_.magnificentSets(n, edges));
}

TEST_P(DivideNodesIntoTheMaximumNumberOfGroupsTest, SelfAuthoredSingleNode) {
  int n = 1;
  std::vector<std::vector<int>> edges = {};
  EXPECT_EQ(1, solution_.magnificentSets(n, edges));
}

TEST_P(DivideNodesIntoTheMaximumNumberOfGroupsTest, SelfAuthoredDisconnectedComponents) {
  int n = 4;
  std::vector<std::vector<int>> edges = {{1, 2}, {3, 4}};
  // Two edges, each component has 2 nodes -> groups: comp1 uses 2, comp2 uses 2
  // total 4.
  EXPECT_EQ(4, solution_.magnificentSets(n, edges));
}

INSTANTIATE_TEST_SUITE_P(
    DivideNodesIntoTheMaximumNumberOfGroupsTest,
    DivideNodesIntoTheMaximumNumberOfGroupsTest,
    ::testing::ValuesIn(
        DivideNodesIntoTheMaximumNumberOfGroupsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2493
