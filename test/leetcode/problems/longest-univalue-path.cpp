#include "leetcode/problems/longest-univalue-path.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_687 {

class LongestUnivaluePathTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongestUnivaluePathSolution solution;
};

TEST_P(LongestUnivaluePathTest, Example1) {
  TreeNode* root = constructTree(std::vector<int>{5, 4, 5, 1, 1, -1, 5});
  EXPECT_EQ(solution.longestUnivaluePath(root), 2);
  delete root;
}

TEST_P(LongestUnivaluePathTest, Example2) {
  TreeNode* root = constructTree(std::vector<int>{1, 4, 5, 4, 4, -1, 5});
  EXPECT_EQ(solution.longestUnivaluePath(root), 2);
  delete root;
}

TEST_P(LongestUnivaluePathTest, SingleNode) {
  TreeNode* root = constructTree(std::vector<int>{1});
  EXPECT_EQ(solution.longestUnivaluePath(root), 0);
  delete root;
}

TEST_P(LongestUnivaluePathTest, EmptyTree) {
  EXPECT_EQ(solution.longestUnivaluePath(nullptr), 0);
}

TEST_P(LongestUnivaluePathTest, AllSameValues) {
  // Tree:      5
  //          /   \
  //         5     5
  //        / \
  //       5   5
  // Longest path: leaf(5) -> left(5) -> root(5) -> right(5) = 3 edges.
  TreeNode* root = constructTree(std::vector<int>{5, 5, 5, 5, 5});
  EXPECT_EQ(solution.longestUnivaluePath(root), 3);
  delete root;
}

TEST_P(LongestUnivaluePathTest, PathThroughRootDifferentArms) {
  // Tree:      1
  //          /   \
  //         1     1
  //        /       \
  //       1         1
  // Longest path: left-left -> left -> root -> right -> right-right = 4 edges.
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{
          std::optional<int>(1), std::optional<int>(1), std::optional<int>(1),
          std::optional<int>(1), std::nullopt, std::nullopt,
          std::optional<int>(1)});
  EXPECT_EQ(solution.longestUnivaluePath(root), 4);
  delete root;
}

TEST_P(LongestUnivaluePathTest, MixedSubtree) {
  // Tree:      1
  //          /   \
  //         1     2
  //        / \
  //       1   1
  // Longest same-value path (value 1): left-left -> left -> left-right = 2
  // edges (bends at 'left' node; cannot also rise to root without branching).
  TreeNode* root = constructTree(std::vector<int>{1, 1, 2, 1, 1});
  EXPECT_EQ(solution.longestUnivaluePath(root), 2);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    LongestUnivaluePathTestSuite, LongestUnivaluePathTest,
    ::testing::ValuesIn(LongestUnivaluePathSolution().getStrategyNames()));

}  // namespace leetcode::problem_687
