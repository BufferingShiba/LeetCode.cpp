#include <gtest/gtest.h>

#include <optional>
#include <vector>

#include "leetcode/problems/maximum-width-of-binary-tree.h"

using namespace leetcode::problem_662;

class MaximumWidthOfBinaryTreeTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }
  MaximumWidthOfBinaryTreeSolution solution_;
};

TEST_P(MaximumWidthOfBinaryTreeTest, Example1) {
  auto root = leetcode::constructTree(
      std::vector<std::optional<int>>{1, 3, 2, 5, 3, std::nullopt, 9});
  EXPECT_EQ(solution_.widthOfBinaryTree(root), 4);
}

TEST_P(MaximumWidthOfBinaryTreeTest, Example2) {
  auto root = leetcode::constructTree(
      std::vector<std::optional<int>>{1, 3, 2, 5, std::nullopt, std::nullopt,
                                       9, 6, std::nullopt, 7});
  EXPECT_EQ(solution_.widthOfBinaryTree(root), 7);
}

TEST_P(MaximumWidthOfBinaryTreeTest, Example3) {
  auto root = leetcode::constructTree(
      std::vector<std::optional<int>>{1, 3, 2, 5});
  EXPECT_EQ(solution_.widthOfBinaryTree(root), 2);
}

TEST_P(MaximumWidthOfBinaryTreeTest, SelfAuthoredSingleNode) {
  auto root = leetcode::constructTree(
      std::vector<std::optional<int>>{42});
  EXPECT_EQ(solution_.widthOfBinaryTree(root), 1);
}

TEST_P(MaximumWidthOfBinaryTreeTest, SelfAuthoredSkewedLeft) {
  auto root = leetcode::constructTree(
      std::vector<std::optional<int>>{1, 2, std::nullopt, 3});
  EXPECT_EQ(solution_.widthOfBinaryTree(root), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MaximumWidthOfBinaryTreeTest,
    testing::ValuesIn(MaximumWidthOfBinaryTreeSolution().getStrategyNames()));
