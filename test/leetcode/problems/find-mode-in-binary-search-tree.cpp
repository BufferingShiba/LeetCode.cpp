#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

#include "leetcode/problems/find-mode-in-binary-search-tree.h"

namespace leetcode::problem_501::test {

namespace {
bool sameSet(const std::vector<int>& a, const std::vector<int>& b) {
  std::vector<int> av = a;
  std::vector<int> bv = b;
  std::sort(av.begin(), av.end());
  std::sort(bv.begin(), bv.end());
  return av == bv;
}
}  // namespace

class FindModeInBinarySearchTreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindModeInBinarySearchTreeSolution solution;
};

TEST_P(FindModeInBinarySearchTreeTest, Example1) {
  //     1
  //      \
  //       2
  //      /
  //     2
  // in-order: 1, 2, 2
  TreeNode* n = new TreeNode(2, new TreeNode(2), nullptr);
  TreeNode* root = new TreeNode(1, nullptr, n);
  std::vector<int> expected = {2};
  EXPECT_TRUE(sameSet(solution.findMode(root), expected));
  delete root;
}

TEST_P(FindModeInBinarySearchTreeTest, Example2SingleNode) {
  TreeNode* root = new TreeNode(0);
  std::vector<int> expected = {0};
  EXPECT_TRUE(sameSet(solution.findMode(root), expected));
  delete root;
}

TEST_P(FindModeInBinarySearchTreeTest, MultipleModes) {
  //     1
  //    / \
  //   1   2
  //      /
  //     2
  // in-order: 1, 1, 2, 2
  TreeNode* root = new TreeNode(1, new TreeNode(1),
                                new TreeNode(2, new TreeNode(2), nullptr));
  std::vector<int> expected = {1, 2};
  EXPECT_TRUE(sameSet(solution.findMode(root), expected));
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    FindModeInBinarySearchTreeTestSuite, FindModeInBinarySearchTreeTest,
    ::testing::ValuesIn(
        FindModeInBinarySearchTreeSolution().getStrategyNames()));

}  // namespace leetcode::problem_501::test
