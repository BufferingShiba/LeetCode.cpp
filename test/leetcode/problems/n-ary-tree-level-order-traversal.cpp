#include "leetcode/problems/n-ary-tree-level-order-traversal.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_429 {

class NAryTreeLevelOrderTraversalTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NAryTreeLevelOrderTraversalSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  root = [1,null,3,2,4,null,5,6]
// Output: [[1],[3,2,4],[5,6]]
TEST_P(NAryTreeLevelOrderTraversalTest, OfficialExample1) {
  Node* n5 = new Node(5);
  Node* n6 = new Node(6);
  Node* n3 = new Node(3);
  n3->children = {n5, n6};
  Node* n2 = new Node(2);
  Node* n4 = new Node(4);
  Node* root = new Node(1);
  root->children = {n3, n2, n4};

  std::vector<std::vector<int>> expected = {{1}, {3, 2, 4}, {5, 6}};
  EXPECT_EQ(expected, solution.levelOrder(root));

  delete root;
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
TEST_P(NAryTreeLevelOrderTraversalTest, OfficialExample2) {
  Node* n14 = new Node(14);
  Node* n13 = new Node(13);
  Node* n12 = new Node(12);
  Node* n11 = new Node(11);
  n11->children = {n14};

  Node* n10 = new Node(10);
  Node* n9 = new Node(9);
  n9->children = {n13};
  Node* n8 = new Node(8);
  n8->children = {n12};

  Node* n7 = new Node(7);
  n7->children = {n11};
  Node* n6 = new Node(6);

  Node* n5 = new Node(5);
  n5->children = {n9, n10};
  Node* n4 = new Node(4);
  n4->children = {n8};
  Node* n3 = new Node(3);
  n3->children = {n6, n7};
  Node* n2 = new Node(2);

  Node* root = new Node(1);
  root->children = {n2, n3, n4, n5};

  std::vector<std::vector<int>> expected = {
      {1}, {2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13}, {14}};
  EXPECT_EQ(expected, solution.levelOrder(root));

  delete root;
}

// ===== Edge Case: empty tree =====
TEST_P(NAryTreeLevelOrderTraversalTest, EmptyTree) {
  EXPECT_EQ(std::vector<std::vector<int>>{}, solution.levelOrder(nullptr));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, NAryTreeLevelOrderTraversalTest,
    ::testing::ValuesIn(NAryTreeLevelOrderTraversalSolution().getStrategyNames()));

}  // namespace problem_429
}  // namespace leetcode
