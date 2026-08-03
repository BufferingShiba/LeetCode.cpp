#include <gtest/gtest.h>

#include <optional>
#include <vector>

#include "leetcode/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level.h"

using namespace leetcode;
using namespace leetcode::problem_2471;

class MinimumNumberOfOperationsToSortABinaryTreeByLevelTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }
  MinimumNumberOfOperationsToSortABinaryTreeByLevelSolution solution_;
};

TEST_P(MinimumNumberOfOperationsToSortABinaryTreeByLevelTest, Example1) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{
      1, 4, 3, 7, 6, 8, 5, std::nullopt, std::nullopt, std::nullopt, std::nullopt, 9, std::nullopt, 10});
  EXPECT_EQ(solution_.minimumOperations(root), 3);
  delete root;
}

TEST_P(MinimumNumberOfOperationsToSortABinaryTreeByLevelTest, Example2) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{1, 3, 2, 7, 6, 5, 4});
  EXPECT_EQ(solution_.minimumOperations(root), 3);
  delete root;
}

TEST_P(MinimumNumberOfOperationsToSortABinaryTreeByLevelTest, Example3) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{1, 2, 3, 4, 5, 6});
  EXPECT_EQ(solution_.minimumOperations(root), 0);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumNumberOfOperationsToSortABinaryTreeByLevelTest,
    testing::ValuesIn(MinimumNumberOfOperationsToSortABinaryTreeByLevelSolution().getStrategyNames()));
