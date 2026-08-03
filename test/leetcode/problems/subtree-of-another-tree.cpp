#include <gtest/gtest.h>

#include <optional>

#include "leetcode/problems/subtree-of-another-tree.h"

using namespace leetcode::problem_572;

class SubtreeOfAnotherTreeTest : public testing::TestWithParam<std::string> {
 protected:
  SubtreeOfAnotherTreeSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(SubtreeOfAnotherTreeTest, Example1) {
  auto* root = leetcode::constructTree(std::vector<int>{3, 4, 5, 1, 2});
  auto* subRoot = leetcode::constructTree(std::vector<int>{4, 1, 2});
  EXPECT_TRUE(solution.isSubtree(root, subRoot));
}

TEST_P(SubtreeOfAnotherTreeTest, Example2) {
  auto* root = leetcode::constructTree(std::vector<std::optional<int>>{
      3, 4, 5, 1, 2, std::nullopt, std::nullopt, std::nullopt, std::nullopt,
      0});
  auto* subRoot = leetcode::constructTree(std::vector<int>{4, 1, 2});
  EXPECT_FALSE(solution.isSubtree(root, subRoot));
}

TEST_P(SubtreeOfAnotherTreeTest, SameTree) {
  auto* root = leetcode::constructTree(std::vector<int>{1});
  auto* subRoot = leetcode::constructTree(std::vector<int>{1});
  EXPECT_TRUE(solution.isSubtree(root, subRoot));
}

TEST_P(SubtreeOfAnotherTreeTest, SingleNodeMatch) {
  auto* root = leetcode::constructTree(std::vector<int>{1, 2});
  auto* subRoot = leetcode::constructTree(std::vector<int>{2});
  EXPECT_TRUE(solution.isSubtree(root, subRoot));
}

INSTANTIATE_TEST_SUITE_P(
    , SubtreeOfAnotherTreeTest,
    testing::ValuesIn(SubtreeOfAnotherTreeSolution().getStrategyNames()));
