#include <gtest/gtest.h>

#include <optional>
#include <string>
#include <vector>

#include "leetcode/problems/univalued-binary-tree.h"

namespace leetcode {
namespace problem_965 {

class UnivaluedBinaryTreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  UnivaluedBinaryTreeSolution solution;
};

TEST_P(UnivaluedBinaryTreeTest, Example1) {
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{1, 1, 1, 1, 1, std::nullopt, 1});
  EXPECT_TRUE(solution.isUnivalTree(root));
  delete root;
}

TEST_P(UnivaluedBinaryTreeTest, Example2) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{2, 2, 2, 5, 2});
  EXPECT_FALSE(solution.isUnivalTree(root));
  delete root;
}

TEST_P(UnivaluedBinaryTreeTest, SelfAuthoredSingleNode) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{7});
  EXPECT_TRUE(solution.isUnivalTree(root));
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    UnivaluedBinaryTreeTestSuite, UnivaluedBinaryTreeTest,
    ::testing::ValuesIn(UnivaluedBinaryTreeSolution().getStrategyNames()));

}  // namespace problem_965
}  // namespace leetcode
