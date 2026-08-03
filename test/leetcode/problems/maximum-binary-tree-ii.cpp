#include "leetcode/problems/maximum-binary-tree-ii.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_998 {

class MaximumBinaryTreeIiTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumBinaryTreeIiSolution solution;
};

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaximumBinaryTreeIiTest,
    ::testing::ValuesIn(MaximumBinaryTreeIiSolution().getStrategyNames()));

// ===== Official Example 1 =====
// root = [4,1,3,null,null,2], val = 5  ->  a=[1,4,2,3], b=[1,4,2,3,5]
// Output: [5,4,null,1,3,null,null,2]  (compact level order: [5,4,1,3,2])
TEST_P(MaximumBinaryTreeIiTest, OfficialExample1) {
  TreeNode* root = leetcode::constructTree(std::vector<int>{4, 1, 3, -1, -1, 2});
  TreeNode* actual = solution.insertIntoMaxTree(root, 5);
  const std::vector<int> expected = {5, 4, 1, 3, 2};
  EXPECT_EQ(expected, leetcode::levelOrderTraversal(actual));
}

// ===== Official Example 2 =====
// root = [5,2,4,null,1], val = 3  ->  Output: [5,2,4,null,1,null,3]
TEST_P(MaximumBinaryTreeIiTest, OfficialExample2) {
  TreeNode* root = leetcode::constructTree(std::vector<int>{5, 2, 4, -1, 1});
  TreeNode* actual = solution.insertIntoMaxTree(root, 3);
  const std::vector<int> expected = {5, 2, 4, 1, 3};
  EXPECT_EQ(expected, leetcode::levelOrderTraversal(actual));
}

// ===== Official Example 3 =====
// root = [5,2,3,null,1], val = 4  ->  Output: [5,2,4,null,1,3]
TEST_P(MaximumBinaryTreeIiTest, OfficialExample3) {
  TreeNode* root = leetcode::constructTree(std::vector<int>{5, 2, 3, -1, 1});
  TreeNode* actual = solution.insertIntoMaxTree(root, 4);
  const std::vector<int> expected = {5, 2, 4, 1, 3};
  EXPECT_EQ(expected, leetcode::levelOrderTraversal(actual));
}

}  // namespace problem_998
}  // namespace leetcode
