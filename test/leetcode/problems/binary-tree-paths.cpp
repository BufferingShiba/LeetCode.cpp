#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/binary-tree-paths.h"

namespace leetcode::problem_257 {

class BinaryTreePathsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  BinaryTreePathsSolution solution_;
};

TEST_P(BinaryTreePathsTest, Example1) {
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{1, 2, 3, std::nullopt, 5});
  std::vector<std::string> expected = {"1->2->5", "1->3"};
  std::vector<std::string> actual = solution_.binaryTreePaths(root);
  EXPECT_EQ(expected, actual);
  delete root;
}

TEST_P(BinaryTreePathsTest, Example2) {
  TreeNode* root = constructTree(std::vector<int>{1});
  std::vector<std::string> expected = {"1"};
  std::vector<std::string> actual = solution_.binaryTreePaths(root);
  EXPECT_EQ(expected, actual);
  delete root;
}

TEST_P(BinaryTreePathsTest, SelfAuthoredSingleLeafOnly) {
  TreeNode* root =
      constructTree(std::vector<std::optional<int>>{5, std::nullopt, 7});
  std::vector<std::string> expected = {"5->7"};
  std::vector<std::string> actual = solution_.binaryTreePaths(root);
  EXPECT_EQ(expected, actual);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    BinaryTreePathsParamTest, BinaryTreePathsTest,
    ::testing::ValuesIn(BinaryTreePathsSolution().getStrategyNames()));

}  // namespace leetcode::problem_257
