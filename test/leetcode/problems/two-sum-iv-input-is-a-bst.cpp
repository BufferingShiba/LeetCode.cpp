#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/two-sum-iv-input-is-a-bst.h"

namespace leetcode {
namespace problem_653 {

using testing::TestWithParam;
using testing::ValuesIn;

class TwoSumIvInputIsABstTest : public TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  TwoSumIvInputIsABstSolution solution;
};

TEST_P(TwoSumIvInputIsABstTest, Example1) {
  TreeNode* root = constructTree(std::vector<int>{5, 3, 6, 2, 4, -1, 7});
  EXPECT_TRUE(solution.findTarget(root, 9));
  delete root;
}

TEST_P(TwoSumIvInputIsABstTest, Example2) {
  TreeNode* root = constructTree(std::vector<int>{5, 3, 6, 2, 4, -1, 7});
  EXPECT_FALSE(solution.findTarget(root, 28));
  delete root;
}

TEST_P(TwoSumIvInputIsABstTest, SelfAuthoredSingleNode) {
  TreeNode* root = constructTree(std::vector<int>{1});
  EXPECT_FALSE(solution.findTarget(root, 2));
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    TwoSumIvInputIsABstTestInstance, TwoSumIvInputIsABstTest,
    ValuesIn(TwoSumIvInputIsABstSolution().getStrategyNames()));

}  // namespace problem_653
}  // namespace leetcode
