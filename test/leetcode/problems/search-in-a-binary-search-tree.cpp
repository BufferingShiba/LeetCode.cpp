#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/search-in-a-binary-search-tree.h"

namespace leetcode::problem_700 {

class SearchInABinarySearchTreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SearchInABinarySearchTreeSolution solution_;
};

TEST_P(SearchInABinarySearchTreeTest, Basic) {
  std::vector<int> values{4, 2, 7, 1, 3};
  TreeNode* root = constructTree(values);
  TreeNode* result = solution_.searchBST(root, 2);
  std::vector<int> expected = {2, 1, 3};
  EXPECT_EQ(preorderTraversal(result), expected);
  delete root;
}

TEST_P(SearchInABinarySearchTreeTest, NotFound) {
  std::vector<int> values{4, 2, 7, 1, 3};
  TreeNode* root = constructTree(values);
  TreeNode* result = solution_.searchBST(root, 5);
  EXPECT_EQ(result, nullptr);
  delete root;
}

TEST_P(SearchInABinarySearchTreeTest, SingleNode) {
  std::vector<int> values{7};
  TreeNode* root = constructTree(values);
  TreeNode* result = solution_.searchBST(root, 7);
  EXPECT_EQ(result->val, 7);
  EXPECT_EQ(result->left, nullptr);
  EXPECT_EQ(result->right, nullptr);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    SearchInABinarySearchTreeTestSuite, SearchInABinarySearchTreeTest,
    ::testing::ValuesIn(SearchInABinarySearchTreeSolution().getStrategyNames()));

}  // namespace leetcode::problem_700
