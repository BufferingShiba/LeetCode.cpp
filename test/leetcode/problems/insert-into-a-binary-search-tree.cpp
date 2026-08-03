#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/insert-into-a-binary-search-tree.h"

namespace leetcode {
namespace problem_701 {

class InsertIntoABinarySearchTreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  InsertIntoABinarySearchTreeSolution solution_;
};

TEST_P(InsertIntoABinarySearchTreeTest, OfficialExample1) {
  auto* root = constructTree(std::vector<std::optional<int>>{4, 2, 7, 1, 3});
  auto* result = solution_.insertIntoBST(root, 5);
  EXPECT_TRUE(isBST(result));
  // Verify 5 is present
  auto inorder = inorderTraversal(result);
  EXPECT_NE(std::find(inorder.begin(), inorder.end(), 5), inorder.end());
}

TEST_P(InsertIntoABinarySearchTreeTest, OfficialExample2) {
  auto* root =
      constructTree(std::vector<std::optional<int>>{40, 20, 60, 10, 30, 50, 70});
  auto* result = solution_.insertIntoBST(root, 25);
  EXPECT_TRUE(isBST(result));
  auto inorder = inorderTraversal(result);
  EXPECT_NE(std::find(inorder.begin(), inorder.end(), 25), inorder.end());
}

TEST_P(InsertIntoABinarySearchTreeTest, OfficialExample3) {
  auto* root =
      constructTree(std::vector<std::optional<int>>{4, 2, 7, 1, 3,
                                                     std::nullopt, std::nullopt,
                                                     std::nullopt, std::nullopt,
                                                     std::nullopt, std::nullopt});
  auto* result = solution_.insertIntoBST(root, 5);
  EXPECT_TRUE(isBST(result));
  auto inorder = inorderTraversal(result);
  EXPECT_NE(std::find(inorder.begin(), inorder.end(), 5), inorder.end());
}

TEST_P(InsertIntoABinarySearchTreeTest, SelfAuthoredInsertIntoEmptyTree) {
  auto* result = solution_.insertIntoBST(nullptr, 42);
  EXPECT_TRUE(isBST(result));
  EXPECT_EQ(result->val, 42);
  EXPECT_EQ(result->left, nullptr);
  EXPECT_EQ(result->right, nullptr);
  delete result;
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    InsertIntoABinarySearchTreeTest,
    ::testing::ValuesIn(
        InsertIntoABinarySearchTreeSolution().getStrategyNames()));

}  // namespace problem_701
}  // namespace leetcode
