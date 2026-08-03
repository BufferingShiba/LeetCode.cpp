#include "leetcode/problems/create-binary-tree-from-descriptions.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2196 {

class CreateBinaryTreeFromDescriptionsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CreateBinaryTreeFromDescriptionsSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output: [50,20,80,15,17,19]
TEST_P(CreateBinaryTreeFromDescriptionsTest, OfficialExample1) {
  std::vector<std::vector<int>> descriptions = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
  TreeNode* result = solution.createBinaryTree(descriptions);
  std::vector<int> expected = {50,20,80,15,17,19};
  EXPECT_EQ(expected, leetcode::levelOrderTraversal(result));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  descriptions = [[1,2,1],[2,3,0],[3,4,1]]
// Output: [1,2,null,null,3,4]
TEST_P(CreateBinaryTreeFromDescriptionsTest, OfficialExample2) {
  std::vector<std::vector<int>> descriptions = {{1,2,1},{2,3,0},{3,4,1}};
  TreeNode* result = solution.createBinaryTree(descriptions);
  std::vector<int> expected = {1,2,3,4};
  EXPECT_EQ(expected, leetcode::levelOrderTraversal(result));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, CreateBinaryTreeFromDescriptionsTest,
    ::testing::ValuesIn(CreateBinaryTreeFromDescriptionsSolution().getStrategyNames()));

}  // namespace problem_2196
}  // namespace leetcode
