#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/evaluate-boolean-binary-tree.h"

namespace leetcode {
namespace problem_2331 {

class EvaluateBooleanBinaryTreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  EvaluateBooleanBinaryTreeSolution solution;
};

TEST_P(EvaluateBooleanBinaryTreeTest, Example1) {
  TreeNode* root = constructTree(std::vector<int>{2, 1, 3, -1, -1, 0, 1});
  EXPECT_TRUE(solution.evaluateTree(root));
}

TEST_P(EvaluateBooleanBinaryTreeTest, Example2) {
  TreeNode* root = constructTree(std::vector<int>{0});
  EXPECT_FALSE(solution.evaluateTree(root));
}

TEST_P(EvaluateBooleanBinaryTreeTest, SelfAuthoredLeafTrue) {
  TreeNode* root = constructTree(std::vector<int>{1});
  EXPECT_TRUE(solution.evaluateTree(root));
}

TEST_P(EvaluateBooleanBinaryTreeTest, SelfAuthoredAndNode) {
  // root=3(AND), left=1, right=1 -> 1&&1 = true
  TreeNode* root = constructTree(std::vector<int>{3, 1, 1});
  EXPECT_TRUE(solution.evaluateTree(root));
}

INSTANTIATE_TEST_SUITE_P(
    EvaluateBooleanBinaryTreeTestSuite, EvaluateBooleanBinaryTreeTest,
    ::testing::ValuesIn(EvaluateBooleanBinaryTreeSolution().getStrategyNames()));

}  // namespace problem_2331
}  // namespace leetcode
