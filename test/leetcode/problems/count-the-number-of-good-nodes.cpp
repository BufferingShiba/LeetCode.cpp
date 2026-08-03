#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-the-number-of-good-nodes.h"

namespace leetcode {
namespace problem_3249 {

class CountTheNumberOfGoodNodesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountTheNumberOfGoodNodesSolution solution;
};

TEST_P(CountTheNumberOfGoodNodesTest, Example1) {
  std::vector<std::vector<int>> edges = {
      {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
  EXPECT_EQ(solution.countGoodNodes(edges), 7);
}

TEST_P(CountTheNumberOfGoodNodesTest, Example2) {
  std::vector<std::vector<int>> edges = {
      {0, 1}, {1, 2}, {2, 3}, {3, 4}, {0, 5}, {1, 6}, {2, 7}, {3, 8}};
  EXPECT_EQ(solution.countGoodNodes(edges), 6);
}

TEST_P(CountTheNumberOfGoodNodesTest, Example3) {
  std::vector<std::vector<int>> edges = {
      {0, 1}, {1, 2}, {1, 3}, {1, 4}, {0, 5}, {5, 6}, {6, 7}, {7, 8}, {0, 9},
      {9, 10}, {9, 12}, {10, 11}};
  EXPECT_EQ(solution.countGoodNodes(edges), 12);
}

TEST_P(CountTheNumberOfGoodNodesTest, SelfAuthoredStarAllGood) {
  // Root 0 with 3 leaf children; every node is good.
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}};
  EXPECT_EQ(solution.countGoodNodes(edges), 4);
}

INSTANTIATE_TEST_SUITE_P(
    CountTheNumberOfGoodNodesTestSuite,
    CountTheNumberOfGoodNodesTest,
    ::testing::ValuesIn(
        CountTheNumberOfGoodNodesSolution().getStrategyNames()));

}  // namespace problem_3249
}  // namespace leetcode
