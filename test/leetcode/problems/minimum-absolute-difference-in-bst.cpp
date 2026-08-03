#include <gtest/gtest.h>

#include <string>

#include "leetcode/core.h"
#include "leetcode/problems/minimum-absolute-difference-in-bst.h"

namespace leetcode {
namespace problem_530 {
namespace {

struct TestCase {
  std::vector<int> tree;
  int expected;
};

}  // namespace

class MinimumAbsoluteDifferenceInBstTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumAbsoluteDifferenceInBstSolution solution;
};

TEST_P(MinimumAbsoluteDifferenceInBstTest, Example1) {
  std::vector<int> tree = {4, 2, 6, 1, 3};
  TreeNode* root = constructTree(tree);
  EXPECT_EQ(solution.getMinimumDifference(root), 1);
  delete root;
}

TEST_P(MinimumAbsoluteDifferenceInBstTest, Example2) {
  std::vector<int> tree = {1, 0, 48, -1, -1, 12, 49};
  TreeNode* root = constructTree(tree);
  EXPECT_EQ(solution.getMinimumDifference(root), 1);
  delete root;
}

TEST_P(MinimumAbsoluteDifferenceInBstTest, SelfAuthored) {
  std::vector<int> tree = {5, 2, 8};
  TreeNode* root = constructTree(tree);
  EXPECT_EQ(solution.getMinimumDifference(root), 3);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    MinimumAbsoluteDifferenceInBstTestCases,
    MinimumAbsoluteDifferenceInBstTest,
    ::testing::ValuesIn(
        MinimumAbsoluteDifferenceInBstSolution().getStrategyNames()));

}  // namespace problem_530
}  // namespace leetcode
