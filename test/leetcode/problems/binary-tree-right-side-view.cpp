#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/binary-tree-right-side-view.h"

namespace leetcode {
namespace problem_199 {

class BinaryTreeRightSideViewTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  BinaryTreeRightSideViewSolution solution_;
};

TEST_P(BinaryTreeRightSideViewTest, Example1) {
  // root = [1,2,3,null,5,null,4]
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{1, 2, 3, std::nullopt, 5, std::nullopt, 4});
  std::vector<int> expected = {1, 3, 4};
  EXPECT_EQ(solution_.rightSideView(root), expected);
  delete root;
}

TEST_P(BinaryTreeRightSideViewTest, Example2) {
  // root = [1,2,3,4,null,null,null,5]
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{1, 2, 3, 4, std::nullopt, std::nullopt, std::nullopt, 5});
  std::vector<int> expected = {1, 3, 4, 5};
  EXPECT_EQ(solution_.rightSideView(root), expected);
  delete root;
}

TEST_P(BinaryTreeRightSideViewTest, Example3) {
  // root = [1,null,3]
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{1, std::nullopt, 3});
  std::vector<int> expected = {1, 3};
  EXPECT_EQ(solution_.rightSideView(root), expected);
  delete root;
}

TEST_P(BinaryTreeRightSideViewTest, Example4) {
  // root = []
  TreeNode* root = constructTree(std::vector<std::optional<int>>{});
  std::vector<int> expected = {};
  EXPECT_EQ(solution_.rightSideView(root), expected);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    BinaryTreeRightSideViewTest,
    testing::ValuesIn(BinaryTreeRightSideViewSolution().getStrategyNames()));

}  // namespace problem_199
}  // namespace leetcode
