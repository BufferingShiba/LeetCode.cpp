#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/pythagorean-distance-nodes-in-a-tree.h"

namespace leetcode {
namespace problem_3820 {

class PythagoreanDistanceNodesInATreeTest
    : public testing::TestWithParam<std::string> {
 protected:
  PythagoreanDistanceNodesInATreeSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(PythagoreanDistanceNodesInATreeTest, Example1) {
  int n = 4;
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}};
  int x = 1, y = 2, z = 3;
  EXPECT_EQ(3, solution.specialNodes(n, edges, x, y, z));
}

TEST_P(PythagoreanDistanceNodesInATreeTest, Example2) {
  int n = 4;
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
  int x = 0, y = 3, z = 2;
  EXPECT_EQ(0, solution.specialNodes(n, edges, x, y, z));
}

TEST_P(PythagoreanDistanceNodesInATreeTest, Example3) {
  int n = 4;
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}};
  int x = 1, y = 3, z = 0;
  EXPECT_EQ(1, solution.specialNodes(n, edges, x, y, z));
}

INSTANTIATE_TEST_SUITE_P(
    PythagoreanDistanceNodesInATreeTestSuite,
    PythagoreanDistanceNodesInATreeTest,
    testing::ValuesIn(
        PythagoreanDistanceNodesInATreeSolution().getStrategyNames()));

}  // namespace problem_3820
}  // namespace leetcode
