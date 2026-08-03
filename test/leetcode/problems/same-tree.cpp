#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/same-tree.h"

namespace leetcode {
namespace problem_100 {
namespace {

using leetcode::TreeNode;
using leetcode::constructTree;

}  // namespace

class SameTreeTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SameTreeSolution solution;
};

TEST_P(SameTreeTest, Example1) {
  TreeNode* p = constructTree(std::vector<int>{1, 2, 3});
  TreeNode* q = constructTree(std::vector<int>{1, 2, 3});
  EXPECT_TRUE(solution.isSameTree(p, q));
  delete p;
  delete q;
}

TEST_P(SameTreeTest, Example2) {
  TreeNode* p = constructTree(std::vector<std::optional<int>>{1, 2, std::nullopt});
  TreeNode* q = constructTree(std::vector<std::optional<int>>{1, std::nullopt, 2});
  EXPECT_FALSE(solution.isSameTree(p, q));
  delete p;
  delete q;
}

TEST_P(SameTreeTest, Example3) {
  TreeNode* p = constructTree(std::vector<int>{1, 2, 1});
  TreeNode* q = constructTree(std::vector<int>{1, 1, 2});
  EXPECT_FALSE(solution.isSameTree(p, q));
  delete p;
  delete q;
}

TEST_P(SameTreeTest, SelfAuthoredBothEmpty) {
  EXPECT_TRUE(solution.isSameTree(nullptr, nullptr));
}

TEST_P(SameTreeTest, SelfAuthoredOneEmpty) {
  TreeNode* p = constructTree(std::vector<int>{1});
  EXPECT_FALSE(solution.isSameTree(p, nullptr));
  delete p;
}

INSTANTIATE_TEST_SUITE_P(
    SameTreeTestSuite, SameTreeTest,
    ::testing::ValuesIn(SameTreeSolution().getStrategyNames()));

}  // namespace problem_100
}  // namespace leetcode
