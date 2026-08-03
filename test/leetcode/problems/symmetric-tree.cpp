#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/symmetric-tree.h"

namespace leetcode {
namespace problem_101 {
namespace {

using testing::TestWithParam;
using testing::Values;
using testing::ValuesIn;

}  // namespace

class SymmetricTreeTest : public TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SymmetricTreeSolution solution;
};

TEST_P(SymmetricTreeTest, Example1) {
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{1, 2, 2, 3, 4, 4, 3});
  EXPECT_TRUE(solution.isSymmetric(root));
  delete root;
}

TEST_P(SymmetricTreeTest, Example2) {
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{1, 2, 2, std::nullopt, 3, std::nullopt, 3});
  EXPECT_FALSE(solution.isSymmetric(root));
  delete root;
}

TEST_P(SymmetricTreeTest, SelfAuthoredSingleNode) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{1});
  EXPECT_TRUE(solution.isSymmetric(root));
  delete root;
}

INSTANTIATE_TEST_SUITE_P(SymmetricTreeTestCases, SymmetricTreeTest,
                         ValuesIn(SymmetricTreeSolution().getStrategyNames()));

}  // namespace problem_101
}  // namespace leetcode
