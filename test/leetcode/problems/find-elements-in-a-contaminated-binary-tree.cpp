#include <gtest/gtest.h>

#include <optional>
#include <vector>

#include "leetcode/problems/find-elements-in-a-contaminated-binary-tree.h"

namespace leetcode::problem_1261 {

class FindElementsInAContaminatedBinaryTreeTest
    : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

INSTANTIATE_TEST_SUITE_P(
    FindElementsInAContaminatedBinaryTreeParameters,
    FindElementsInAContaminatedBinaryTreeTest,
    ::testing::Values(0));

TEST_P(FindElementsInAContaminatedBinaryTreeTest, Example1) {
  leetcode::TreeNode* root = leetcode::constructTree(
      std::vector<std::optional<int>>{-1, std::nullopt, -1});
  FindElements fe(root);
  EXPECT_FALSE(fe.find(1));
  EXPECT_TRUE(fe.find(2));
  delete root;
}

TEST_P(FindElementsInAContaminatedBinaryTreeTest, SelfAuthoredExample2) {
  leetcode::TreeNode* root = leetcode::constructTree(
      std::vector<std::optional<int>>{-1, -1, -1, -1, -1});
  FindElements fe(root);
  EXPECT_TRUE(fe.find(1));
  EXPECT_TRUE(fe.find(3));
  EXPECT_FALSE(fe.find(5));
  delete root;
}

TEST_P(FindElementsInAContaminatedBinaryTreeTest, SelfAuthoredExample3) {
  leetcode::TreeNode* root = leetcode::constructTree(
      std::vector<std::optional<int>>{-1, std::nullopt, -1, -1,
                                      std::nullopt, -1});
  FindElements fe(root);
  EXPECT_TRUE(fe.find(2));
  EXPECT_FALSE(fe.find(3));
  EXPECT_FALSE(fe.find(4));
  EXPECT_TRUE(fe.find(5));
  delete root;
}

}  // namespace leetcode::problem_1261
