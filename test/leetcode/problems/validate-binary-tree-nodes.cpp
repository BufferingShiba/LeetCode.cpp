#include "leetcode/problems/validate-binary-tree-nodes.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1361 {

class ValidateBinaryTreeNodesTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ValidateBinaryTreeNodesSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
// Output: true
TEST_P(ValidateBinaryTreeNodesTest, OfficialExample1) {
  int n = 4;
  std::vector<int> leftChild = {1, -1, 3, -1};
  std::vector<int> rightChild = {2, -1, -1, -1};
  bool expected = true;
  EXPECT_EQ(expected, solution.validateBinaryTreeNodes(n, leftChild, rightChild));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
// Output: false
TEST_P(ValidateBinaryTreeNodesTest, OfficialExample2) {
  int n = 4;
  std::vector<int> leftChild = {1, -1, 3, -1};
  std::vector<int> rightChild = {2, 3, -1, -1};
  bool expected = false;
  EXPECT_EQ(expected, solution.validateBinaryTreeNodes(n, leftChild, rightChild));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  n = 2, leftChild = [1,0], rightChild = [-1,-1]
// Output: false
TEST_P(ValidateBinaryTreeNodesTest, OfficialExample3) {
  int n = 2;
  std::vector<int> leftChild = {1, 0};
  std::vector<int> rightChild = {-1, -1};
  bool expected = false;
  EXPECT_EQ(expected, solution.validateBinaryTreeNodes(n, leftChild, rightChild));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, ValidateBinaryTreeNodesTest,
    ::testing::ValuesIn(ValidateBinaryTreeNodesSolution().getStrategyNames()));

}  // namespace problem_1361
}  // namespace leetcode
