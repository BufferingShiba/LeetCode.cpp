#include <gtest/gtest.h>

#include <optional>
#include <string>
#include <vector>

#include "leetcode/problems/maximum-difference-between-node-and-ancestor.h"

namespace leetcode {
namespace problem_1026 {

class MaximumDifferenceBetweenNodeAndAncestorTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  MaximumDifferenceBetweenNodeAndAncestorSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MaximumDifferenceBetweenNodeAndAncestorTest, Example1) {
  TreeNode* root = constructTree(
      std::vector<int>{8, 3, 10, 1, 6, -1, 14, -1, -1, 4, 7, 13});
  EXPECT_EQ(7, solution.maxAncestorDiff(root));
}

TEST_P(MaximumDifferenceBetweenNodeAndAncestorTest, Example2) {
  TreeNode* root = constructTree(std::vector<int>{1, -1, 2, -1, 0, 3});
  EXPECT_EQ(3, solution.maxAncestorDiff(root));
}

TEST_P(MaximumDifferenceBetweenNodeAndAncestorTest, SelfAuthoredChain) {
  // Tree: 5 -> left 3 (left 2, right 7), right 8.
  // Root-to-node max-min: node 7 gives |3-7| = 4 -> max answer 4.
  TreeNode* root = constructTree(std::vector<std::optional<int>>{
      5, 3, 8, 2, 7, std::nullopt, std::nullopt});
  EXPECT_EQ(4, solution.maxAncestorDiff(root));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumDifferenceBetweenNodeAndAncestorTestParameters,
    MaximumDifferenceBetweenNodeAndAncestorTest,
    ::testing::ValuesIn(
        MaximumDifferenceBetweenNodeAndAncestorSolution().getStrategyNames()));

}  // namespace problem_1026
}  // namespace leetcode
