#include "leetcode/problems/number-of-restricted-paths-from-first-to-last-node.h"

#include "gtest/gtest.h"

#include <vector>

namespace leetcode {
namespace problem_1786 {

class NumberOfRestrictedPathsFromFirstToLastNodeTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfRestrictedPathsFromFirstToLastNodeSolution solution;
};

TEST_P(NumberOfRestrictedPathsFromFirstToLastNodeTest, Example1) {
  int n = 5;
  vector<vector<int>> edges = {{1, 2, 3}, {1, 3, 3}, {2, 3, 1}, {1, 4, 2},
                               {5, 2, 2}, {3, 5, 1}, {5, 4, 10}};
  EXPECT_EQ(solution.countRestrictedPaths(n, edges), 3);
}

TEST_P(NumberOfRestrictedPathsFromFirstToLastNodeTest, Example2) {
  int n = 7;
  vector<vector<int>> edges = {{1, 3, 1}, {4, 1, 2}, {7, 3, 4}, {2, 5, 3},
                               {5, 6, 1}, {6, 7, 2}, {7, 5, 3}, {2, 6, 4}};
  EXPECT_EQ(solution.countRestrictedPaths(n, edges), 1);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, NumberOfRestrictedPathsFromFirstToLastNodeTest,
    ::testing::ValuesIn(NumberOfRestrictedPathsFromFirstToLastNodeSolution().getStrategyNames()));

}  // namespace problem_1786
}  // namespace leetcode
