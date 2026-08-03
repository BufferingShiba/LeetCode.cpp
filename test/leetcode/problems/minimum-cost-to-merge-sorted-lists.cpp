#include <gtest/gtest.h>

#include "leetcode/problems/minimum-cost-to-merge-sorted-lists.h"

using namespace leetcode::problem_3801;

class MinimumCostToMergeSortedListsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MinimumCostToMergeSortedListsSolution solution;
};

TEST_P(MinimumCostToMergeSortedListsTest, Example1) {
  std::vector<std::vector<int>> lists = {{1, 3, 5}, {2, 4}, {6, 7, 8}};
  EXPECT_EQ(solution.minMergeCost(lists), 18);
}

TEST_P(MinimumCostToMergeSortedListsTest, Example2) {
  std::vector<std::vector<int>> lists = {{1, 1, 5}, {1, 4, 7, 8}};
  EXPECT_EQ(solution.minMergeCost(lists), 10);
}

TEST_P(MinimumCostToMergeSortedListsTest, Example3) {
  std::vector<std::vector<int>> lists = {{1}, {3}};
  EXPECT_EQ(solution.minMergeCost(lists), 4);
}

TEST_P(MinimumCostToMergeSortedListsTest, Example4) {
  std::vector<std::vector<int>> lists = {{1}, {1}};
  EXPECT_EQ(solution.minMergeCost(lists), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumCostToMergeSortedListsTest,
    testing::ValuesIn(
        MinimumCostToMergeSortedListsSolution().getStrategyNames()));
