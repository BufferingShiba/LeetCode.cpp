#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/root-equals-sum-of-children.h"
#include "leetcode/utils/tree.h"

namespace leetcode {
namespace problem_2236 {
namespace {

using leetcode::constructTree;
using leetcode::TreeNode;

class RootEqualsSumOfChildrenTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RootEqualsSumOfChildrenSolution solution;
};

TEST_P(RootEqualsSumOfChildrenTest, Example1) {
  TreeNode* root = constructTree(std::vector<int>{10, 4, 6});
  EXPECT_TRUE(solution.getSolution()(root));
  delete root;
}

TEST_P(RootEqualsSumOfChildrenTest, Example2) {
  TreeNode* root = constructTree(std::vector<int>{5, 3, 1});
  EXPECT_FALSE(solution.getSolution()(root));
  delete root;
}

TEST_P(RootEqualsSumOfChildrenTest, SelfAuthoredNegativeValues) {
  TreeNode* root = constructTree(std::vector<int>{-5, -3, -2});
  EXPECT_TRUE(solution.getSolution()(root));
  delete root;
}

INSTANTIATE_TEST_SUITE_P(RootEqualsSumOfChildrenTestSuite,
                         RootEqualsSumOfChildrenTest,
                         ::testing::ValuesIn(
                             RootEqualsSumOfChildrenSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2236
}  // namespace leetcode
