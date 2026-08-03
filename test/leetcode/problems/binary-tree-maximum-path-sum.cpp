#include <gtest/gtest.h>

#include <memory>
#include <string>
#include <vector>

#include "leetcode/problems/binary-tree-maximum-path-sum.h"

namespace leetcode {
namespace problem_124 {
namespace {

class BinaryTreeMaximumPathSumTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  BinaryTreeMaximumPathSumSolution solution_;
};

TEST_P(BinaryTreeMaximumPathSumTest, Example1) {
  TreeNode* root = constructTree(std::vector<int>{1, 2, 3});
  EXPECT_EQ(solution_.maxPathSum(root), 6);
  delete root;
}

TEST_P(BinaryTreeMaximumPathSumTest, Example2) {
  TreeNode* root =
      constructTree(std::vector<int>{-10, 9, 20, -1, -1, 15, 7});
  EXPECT_EQ(solution_.maxPathSum(root), 42);
  delete root;
}

TEST_P(BinaryTreeMaximumPathSumTest, SelfAuthoredSingleNegativeNode) {
  TreeNode* root = constructTree(std::vector<int>{-3});
  EXPECT_EQ(solution_.maxPathSum(root), -3);
  delete root;
}

TEST_P(BinaryTreeMaximumPathSumTest, SelfAuthoredAllNegativeTree) {
  TreeNode* root =
      constructTree(std::vector<int>{-10, -20, -30, -40, -50, -60, -70});
  // max single node = -10
  EXPECT_EQ(solution_.maxPathSum(root), -10);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    BinaryTreeMaximumPathSumTestSuite, BinaryTreeMaximumPathSumTest,
    ::testing::ValuesIn(BinaryTreeMaximumPathSumSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_124
}  // namespace leetcode
