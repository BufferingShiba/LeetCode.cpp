#include <gtest/gtest.h>

#include <climits>
#include <string>
#include <vector>

#include "leetcode/problems/merge-bsts-to-create-single-bst.h"
#include "leetcode/utils/tree.h"

namespace leetcode::problem_1932 {
namespace {

std::vector<TreeNode*> buildTrees(
    const std::vector<std::vector<int>>& lists) {
  std::vector<TreeNode*> trees;
  for (const auto& list : lists) {
    trees.push_back(leetcode::constructTree(list));
  }
  return trees;
}

}  // namespace

class MergeBstsToCreateSingleBstTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MergeBstsToCreateSingleBstSolution solution;
};

TEST_P(MergeBstsToCreateSingleBstTest, Example1) {
  auto trees = buildTrees({{2, 1}, {3, 2, 5}, {5, 4}});
  auto expected = leetcode::constructTree(
      std::vector<int>{3, 2, 5, 1, -1, 4});
  auto result = solution.canMerge(trees);
  EXPECT_TRUE(leetcode::isSameTree(result, expected));
}

TEST_P(MergeBstsToCreateSingleBstTest, Example2) {
  auto trees = buildTrees({{5, 3, 8}, {3, 2, 6}});
  EXPECT_EQ(solution.canMerge(trees), nullptr);
}

TEST_P(MergeBstsToCreateSingleBstTest, Example3) {
  auto trees = buildTrees({{5, 4}, {3}});
  EXPECT_EQ(solution.canMerge(trees), nullptr);
}

TEST_P(MergeBstsToCreateSingleBstTest, SelfAuthoredSingleTree) {
  auto trees = buildTrees({{2, 1, 3}});
  auto expected = leetcode::constructTree(std::vector<int>{2, 1, 3});
  auto result = solution.canMerge(trees);
  EXPECT_TRUE(leetcode::isSameTree(result, expected));
}

TEST_P(MergeBstsToCreateSingleBstTest, SelfAuthoredDuplicateRootAsChildInvalid) {
  // Value 3 is a root in one tree and appears twice as non-root in others.
  auto trees = buildTrees({{5, 3, 8}, {3, 2, 6}, {4, 3, 9}});
  EXPECT_EQ(solution.canMerge(trees), nullptr);
}

INSTANTIATE_TEST_SUITE_P(
    MergeBstsToCreateSingleBstTestCases, MergeBstsToCreateSingleBstTest,
    ::testing::ValuesIn(MergeBstsToCreateSingleBstSolution().getStrategyNames()));

}  // namespace leetcode::problem_1932
