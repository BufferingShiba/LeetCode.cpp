#include <gtest/gtest.h>

#include <optional>
#include <vector>

#include "leetcode/problems/kth-largest-sum-in-a-binary-tree.h"

namespace leetcode {
namespace problem_2583 {
namespace {

class KthLargestSumInABinaryTreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  KthLargestSumInABinaryTreeSolution solution_;
};

TEST_P(KthLargestSumInABinaryTreeTest, Example1) {
  // root = [5,8,9,2,1,3,7,4,6], k = 2 → output 13
  TreeNode* root = constructTree(std::vector<int>{5, 8, 9, 2, 1, 3, 7, 4, 6});
  int k = 2;
  long long expected = 13;
  EXPECT_EQ(solution_.kthLargestLevelSum(root, k), expected);
  delete root;
}

TEST_P(KthLargestSumInABinaryTreeTest, Example2) {
  // root = [1,2,null,3], k = 1 → output 3
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{1, 2, std::nullopt, 3});
  int k = 1;
  long long expected = 3;
  EXPECT_EQ(solution_.kthLargestLevelSum(root, k), expected);
  delete root;
}

TEST_P(KthLargestSumInABinaryTreeTest, SelfAuthoredKGreaterThanLevels) {
  // Only 2 levels, k=5 → return -1
  TreeNode* root = constructTree(std::vector<int>{1, 2, 3});
  int k = 5;
  long long expected = -1;
  EXPECT_EQ(solution_.kthLargestLevelSum(root, k), expected);
  delete root;
}

TEST_P(KthLargestSumInABinaryTreeTest, SelfAuthoredKEqualsNumberOfLevels) {
  // 2 levels: level1=1, level2=5. The 2nd largest = 1.
  TreeNode* root = constructTree(std::vector<int>{1, 2, 3});
  int k = 2;
  long long expected = 1;
  EXPECT_EQ(solution_.kthLargestLevelSum(root, k), expected);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    KthLargestSumInABinaryTreeTest,
    ::testing::ValuesIn(
        KthLargestSumInABinaryTreeSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2583
}  // namespace leetcode
