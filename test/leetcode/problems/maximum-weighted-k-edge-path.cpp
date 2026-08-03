#include <gtest/gtest.h>

#include "leetcode/problems/maximum-weighted-k-edge-path.h"

namespace leetcode {
namespace problem_3543 {
namespace {

class MaximumWeightedKEdgePathTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumWeightedKEdgePathSolution solution_;
};

TEST_P(MaximumWeightedKEdgePathTest, Example1) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 2, 2}};
  int k = 2, t = 4;
  EXPECT_EQ(3, solution_.maxWeight(n, edges, k, t));
}

TEST_P(MaximumWeightedKEdgePathTest, Example2) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1, 2}, {0, 2, 3}};
  int k = 1, t = 3;
  EXPECT_EQ(2, solution_.maxWeight(n, edges, k, t));
}

TEST_P(MaximumWeightedKEdgePathTest, Example3) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1, 6}, {1, 2, 8}};
  int k = 1, t = 6;
  EXPECT_EQ(-1, solution_.maxWeight(n, edges, k, t));
}

TEST_P(MaximumWeightedKEdgePathTest, SelfAuthoredEdgeCaseNoEdges) {
  int n = 4;
  std::vector<std::vector<int>> edges = {};
  int k = 2, t = 10;
  EXPECT_EQ(-1, solution_.maxWeight(n, edges, k, t));
}

TEST_P(MaximumWeightedKEdgePathTest, SelfAuthoredEdgeCaseKZero) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1, 5}};
  int k = 0, t = 5;
  EXPECT_EQ(0, solution_.maxWeight(n, edges, k, t));
}

TEST_P(MaximumWeightedKEdgePathTest, SelfAuthoredEdgeCaseSkipEdgeWeightEqualToT) {
  // path sum equals t should be rejected; pick maximum strictly below t
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1, 3}, {0, 2, 2}};
  int k = 1, t = 3;
  EXPECT_EQ(2, solution_.maxWeight(n, edges, k, t));
}


// LeetCode 失败用例: WrongAnswerCase1
TEST_P(MaximumWeightedKEdgePathTest, WrongAnswerCase1) {
  int n = 4;
    std::vector<std::vector<int>> edges = {{0, 1, 4}, {0, 2, 3}, {1, 2, 9}, {2, 3, 5}, {0, 3, 5}};
    int k = 2, t = 11;
    EXPECT_EQ(8, solution_.maxWeight(n, edges, k, t));
}
INSTANTIATE_TEST_SUITE_P(
    MaximumWeightedKEdgePathTestSuite,
    MaximumWeightedKEdgePathTest,
    ::testing::ValuesIn(
        MaximumWeightedKEdgePathSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3543
}  // namespace leetcode
