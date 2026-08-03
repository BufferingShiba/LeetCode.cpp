#include <gtest/gtest.h>

#include <optional>
#include <string>
#include <vector>

#include "leetcode/problems/cousins-in-binary-tree.h"

namespace leetcode {
namespace problem_993 {

class CousinsInBinaryTreeTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CousinsInBinaryTreeSolution solution_;
};

TEST_P(CousinsInBinaryTreeTest, Example1) {
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{1, 2, 3, 4});
  EXPECT_FALSE(solution_.isCousins(root, 4, 3));
  delete root;
}

TEST_P(CousinsInBinaryTreeTest, Example2) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{
      1, 2, 3, std::nullopt, 4, std::nullopt, 5});
  EXPECT_TRUE(solution_.isCousins(root, 5, 4));
  delete root;
}

TEST_P(CousinsInBinaryTreeTest, Example3) {
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{1, 2, 3, std::nullopt, 4});
  EXPECT_FALSE(solution_.isCousins(root, 2, 3));
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    CousinsInBinaryTreeTestSuite, CousinsInBinaryTreeTest,
    testing::ValuesIn(CousinsInBinaryTreeSolution().getStrategyNames()));

}  // namespace problem_993
}  // namespace leetcode
