#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/maximum-product-of-splitted-binary-tree.h"

namespace leetcode {
namespace problem_1339 {
namespace {

using testing::TestWithParam;
using testing::ValuesIn;

class MaximumProductOfSplittedBinaryTreeTest
    : public TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumProductOfSplittedBinaryTreeSolution solution;
};

TEST_P(MaximumProductOfSplittedBinaryTreeTest, Example1) {
  TreeNode* root = constructTree(std::vector<int>{1, 2, 3, 4, 5, 6});
  EXPECT_EQ(solution.maxProduct(root), 110);
  delete root;
}

TEST_P(MaximumProductOfSplittedBinaryTreeTest, Example2) {
  TreeNode* root =
      constructTree(std::vector<int>{1, -1, 2, 3, 4, -1, -1, 5, 6});
  EXPECT_EQ(solution.maxProduct(root), 90);
  delete root;
}

TEST_P(MaximumProductOfSplittedBinaryTreeTest, TwoNodes) {
  TreeNode* root = constructTree(std::vector<int>{2, 7});
  EXPECT_EQ(solution.maxProduct(root), 14);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    MaximumProductOfSplittedBinaryTreeStrategies,
    MaximumProductOfSplittedBinaryTreeTest,
    ValuesIn(MaximumProductOfSplittedBinaryTreeSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1339
}  // namespace leetcode
