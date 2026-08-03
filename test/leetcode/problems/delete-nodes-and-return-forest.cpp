#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/delete-nodes-and-return-forest.h"

using namespace leetcode;
using namespace leetcode::problem_1110;

class DeleteNodesAndReturnForestTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  DeleteNodesAndReturnForestSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }

  bool compareForests(const std::vector<TreeNode*>& result,
                      const std::vector<TreeNode*>& expected) {
    if (result.size() != expected.size()) return false;
    std::vector<bool> used(expected.size(), false);
    for (auto* r : result) {
      bool found = false;
      for (size_t i = 0; i < expected.size(); ++i) {
        if (!used[i] && isSameTree(r, expected[i])) {
          used[i] = true;
          found = true;
          break;
        }
      }
      if (!found) return false;
    }
    return true;
  }
};

TEST_P(DeleteNodesAndReturnForestTest, Example1) {
  TreeNode* root = constructTree(std::vector<int>{1, 2, 3, 4, 5, 6, 7});
  std::vector<int> to_delete = {3, 5};
  auto result = solution.delNodes(root, to_delete);

  TreeNode* t1 = constructTree(std::vector<int>{1, 2, -1, 4});
  TreeNode* t2 = constructTree(std::vector<int>{6});
  TreeNode* t3 = constructTree(std::vector<int>{7});
  std::vector<TreeNode*> expected = {t1, t2, t3};

  EXPECT_TRUE(compareForests(result, expected));

  for (auto* r : result) delete r;
  for (auto* e : expected) delete e;
}

TEST_P(DeleteNodesAndReturnForestTest, Example2) {
  TreeNode* root = constructTree(std::vector<int>{1, 2, 4, -1, 3});
  std::vector<int> to_delete = {3};
  auto result = solution.delNodes(root, to_delete);

  TreeNode* t1 = constructTree(std::vector<int>{1, 2, 4});
  std::vector<TreeNode*> expected = {t1};

  EXPECT_TRUE(compareForests(result, expected));

  for (auto* r : result) delete r;
  for (auto* e : expected) delete e;
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    DeleteNodesAndReturnForestTest,
    ::testing::ValuesIn(
        DeleteNodesAndReturnForestSolution().getStrategyNames()));
