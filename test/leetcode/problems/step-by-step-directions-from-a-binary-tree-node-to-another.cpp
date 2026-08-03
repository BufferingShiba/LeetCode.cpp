#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/step-by-step-directions-from-a-binary-tree-node-to-another.h"
#include "leetcode/utils/tree.h"

namespace leetcode::problem_2096 {

class StepByStepDirectionsFromABinaryTreeNodeToAnotherTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  StepByStepDirectionsFromABinaryTreeNodeToAnotherSolution solution;
};

TEST_P(StepByStepDirectionsFromABinaryTreeNodeToAnotherTest, Example1) {
  TreeNode* root =
      constructTree(std::vector<int>{5, 1, 2, 3, -1, 6, 4});
  EXPECT_EQ(solution.getDirections(root, 3, 6), "UURL");
  delete root;
}

TEST_P(StepByStepDirectionsFromABinaryTreeNodeToAnotherTest, Example2) {
  TreeNode* root = constructTree(std::vector<int>{2, 1});
  EXPECT_EQ(solution.getDirections(root, 2, 1), "L");
  delete root;
}

TEST_P(StepByStepDirectionsFromABinaryTreeNodeToAnotherTest, SameParentRightChild) {
  TreeNode* root = constructTree(std::vector<int>{2, 1});
  // start = 1 (left child), dest = 2 (root parent) => go up.
  EXPECT_EQ(solution.getDirections(root, 1, 2), "U");
  delete root;
}

TEST_P(StepByStepDirectionsFromABinaryTreeNodeToAnotherTest, LeftRightSiblings) {
  TreeNode* root = constructTree(std::vector<int>{5, 1, 2});
  // start = 1 (left), dest = 2 (right), LCA = 5.
  EXPECT_EQ(solution.getDirections(root, 1, 2), "UR");
  delete root;
}

TEST_P(StepByStepDirectionsFromABinaryTreeNodeToAnotherTest, DeepRightDown) {
  TreeNode* root = constructTree(std::vector<int>{1, 2, 3, -1, -1, 6, 7});
  // start = 1 (root), dest = 7: path 1 -> 3 -> 7 (R then R).
  EXPECT_EQ(solution.getDirections(root, 1, 7), "RR");
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    StepByStepDirectionsFromABinaryTreeNodeToAnotherTestSuite,
    StepByStepDirectionsFromABinaryTreeNodeToAnotherTest,
    ::testing::ValuesIn(
        StepByStepDirectionsFromABinaryTreeNodeToAnotherSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_2096
