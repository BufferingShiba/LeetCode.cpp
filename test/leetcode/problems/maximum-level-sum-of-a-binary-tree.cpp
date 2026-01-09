#include "leetcode/problems/maximum-level-sum-of-a-binary-tree.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1161 {

class MaximumLevelSumOfABinaryTreeTest
    : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumLevelSumOfABinaryTreeSolution solution;
};

TEST_P(MaximumLevelSumOfABinaryTreeTest, Example1) {
  vector<int> values = {1, 7, 0, 7, -8};
  TreeNode* root = constructTree(values);
  int expected = 2;
  int result = solution.maxLevelSum(root);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximumLevelSumOfABinaryTreeTest, Example2) {
  // root = [989,null,10250,98693,-89388,null,null,null,-32127]
  vector<optional<int>> values = {989,     nullopt, 10250,   98693, -89388,
                                  nullopt, nullopt, nullopt, -32127};
  TreeNode* root = constructTree(values);
  int expected = 2;
  int result = solution.maxLevelSum(root);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximumLevelSumOfABinaryTreeTest, SingleNode) {
  vector<int> values = {100};
  TreeNode* root = constructTree(values);
  int expected = 1;
  int result = solution.maxLevelSum(root);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximumLevelSumOfABinaryTreeTest, AllPositive) {
  vector<int> values = {1, 2, 3, 4, 5, 6, 7};
  TreeNode* root = constructTree(values);
  int expected = 3;
  int result = solution.maxLevelSum(root);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximumLevelSumOfABinaryTreeTest, NegativeValues) {
  vector<int> values = {-10, -5, -3};
  TreeNode* root = constructTree(values);
  int expected = 2;
  int result = solution.maxLevelSum(root);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximumLevelSumOfABinaryTreeTest, TieBreaker) {
  vector<int> values = {1, 2, 2, 3, 3, 3, 3};
  TreeNode* root = constructTree(values);
  int expected = 3;
  int result = solution.maxLevelSum(root);
  EXPECT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaximumLevelSumOfABinaryTreeTest,
    ::testing::ValuesIn(
        MaximumLevelSumOfABinaryTreeSolution().getStrategyNames()));

}  // namespace problem_1161
}  // namespace leetcode