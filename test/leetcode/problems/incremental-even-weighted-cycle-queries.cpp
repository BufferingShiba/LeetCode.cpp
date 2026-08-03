#include <gtest/gtest.h>

#include "leetcode/problems/incremental-even-weighted-cycle-queries.h"

using namespace leetcode::problem_3887;

class IncrementalEvenWeightedCycleQueriesTest
    : public testing::TestWithParam<std::string> {
 protected:
  IncrementalEvenWeightedCycleQueriesSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(IncrementalEvenWeightedCycleQueriesTest, Example1) {
  std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 1}};
  EXPECT_EQ(solution.numberOfEdgesAdded(3, edges), 2);
}

TEST_P(IncrementalEvenWeightedCycleQueriesTest, Example2) {
  std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 0}};
  EXPECT_EQ(solution.numberOfEdgesAdded(3, edges), 3);
}

TEST_P(IncrementalEvenWeightedCycleQueriesTest, SelfAuthoredAllEdgesAddedTree) {
  // A tree – no cycles, all edges should be added
  std::vector<std::vector<int>> edges = {
      {0, 1, 0}, {1, 2, 1}, {2, 3, 0}, {3, 4, 1}};
  EXPECT_EQ(solution.numberOfEdgesAdded(5, edges), 4);
}

TEST_P(IncrementalEvenWeightedCycleQueriesTest, SelfAuthoredEvenCycleAllAdded) {
  // Forms an even cycle (0-1-2-3-0 with weights 0,1,0,1 → XOR=0)
  std::vector<std::vector<int>> edges = {
      {0, 1, 0}, {1, 2, 1}, {2, 3, 0}, {3, 0, 1}};
  EXPECT_EQ(solution.numberOfEdgesAdded(4, edges), 4);
}

TEST_P(IncrementalEvenWeightedCycleQueriesTest, SelfAuthoredOddCycleBlocked) {
  // First edge of cycle after tree blocks due to odd parity
  std::vector<std::vector<int>> edges = {
      {0, 1, 0}, {1, 2, 0}, {0, 2, 1}};
  // 0-1-0, 1-2-0: parity(0→2)=0, but w=1 → blocked
  EXPECT_EQ(solution.numberOfEdgesAdded(3, edges), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, IncrementalEvenWeightedCycleQueriesTest,
    testing::ValuesIn(
        IncrementalEvenWeightedCycleQueriesSolution().getStrategyNames()));
