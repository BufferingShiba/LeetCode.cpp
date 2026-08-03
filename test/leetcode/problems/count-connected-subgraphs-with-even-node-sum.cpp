#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-connected-subgraphs-with-even-node-sum.h"

namespace leetcode {
namespace problem_3910 {
namespace {

class CountConnectedSubgraphsWithEvenNodeSumTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  CountConnectedSubgraphsWithEvenNodeSumSolution solution;
};

TEST_P(CountConnectedSubgraphsWithEvenNodeSumTest, Example1) {
  std::vector<int> nums = {1, 0, 1};
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}};
  EXPECT_EQ(2, solution.evenSumSubgraphs(nums, edges));
}

TEST_P(CountConnectedSubgraphsWithEvenNodeSumTest, Example2) {
  std::vector<int> nums = {1};
  std::vector<std::vector<int>> edges = {};
  EXPECT_EQ(0, solution.evenSumSubgraphs(nums, edges));
}

INSTANTIATE_TEST_SUITE_P(
    CountConnectedSubgraphsWithEvenNodeSumTestInstance,
    CountConnectedSubgraphsWithEvenNodeSumTest,
    ::testing::ValuesIn(CountConnectedSubgraphsWithEvenNodeSumSolution()
                            .getStrategyNames()));

}  // namespace
}  // namespace problem_3910
}  // namespace leetcode
