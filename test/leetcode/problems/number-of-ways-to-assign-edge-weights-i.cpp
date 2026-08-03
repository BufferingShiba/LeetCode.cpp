#include "leetcode/problems/number-of-ways-to-assign-edge-weights-i.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3558 {
namespace {

class NumberOfWaysToAssignEdgeWeightsITest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfWaysToAssignEdgeWeightsISolution solution;
};

TEST_P(NumberOfWaysToAssignEdgeWeightsITest, Example1) {
  std::vector<std::vector<int>> edges = {{1, 2}};
  EXPECT_EQ(1, solution.assignEdgeWeights(edges));
}

TEST_P(NumberOfWaysToAssignEdgeWeightsITest, Example2) {
  std::vector<std::vector<int>> edges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
  EXPECT_EQ(2, solution.assignEdgeWeights(edges));
}

TEST_P(NumberOfWaysToAssignEdgeWeightsITest, SelfAuthoredStarRootOnlyChildren) {
  // 根1有3个子节点，最大深度=1，方案数 2^(1-1)=1。
  std::vector<std::vector<int>> edges = {{1, 2}, {1, 3}, {1, 4}};
  EXPECT_EQ(1, solution.assignEdgeWeights(edges));
}

TEST_P(NumberOfWaysToAssignEdgeWeightsITest, SelfAuthoredChainLength3) {
  // 1-2-3-4，最大深度=3，方案数 2^(3-1)=4。
  std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}};
  EXPECT_EQ(4, solution.assignEdgeWeights(edges));
}

TEST_P(NumberOfWaysToAssignEdgeWeightsITest, SelfAuthoredMixedTreeMaximumBranch) {
  // 1-2, 2-3, 3-4, 且 2-5。最大深度(从1)=3，方案数 2^(3-1)=4。
  std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {2, 5}};
  EXPECT_EQ(4, solution.assignEdgeWeights(edges));
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfWaysToAssignEdgeWeightsITestSuite,
    NumberOfWaysToAssignEdgeWeightsITest,
    testing::ValuesIn(NumberOfWaysToAssignEdgeWeightsISolution()
                          .getStrategyNames()));

}  // namespace
}  // namespace problem_3558
}  // namespace leetcode
