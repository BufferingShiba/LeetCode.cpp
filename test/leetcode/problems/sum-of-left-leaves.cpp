#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/sum-of-left-leaves.h"

namespace leetcode::problem_404 {

class SumOfLeftLeavesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SumOfLeftLeavesSolution solution_;
};

TEST_P(SumOfLeftLeavesTest, Example1) {
  TreeNode* root = leetcode::constructTree(
      std::vector<std::optional<int>>{3, 9, 20, std::nullopt, std::nullopt, 15, 7});
  EXPECT_EQ(24, solution_.sumOfLeftLeaves(root));
  delete root;
}

TEST_P(SumOfLeftLeavesTest, Example2) {
  TreeNode* root = leetcode::constructTree(std::vector<int>{1});
  EXPECT_EQ(0, solution_.sumOfLeftLeaves(root));
  delete root;
}

TEST_P(SumOfLeftLeavesTest, SelfAuthoredLeftLeafOnlySingle) {
  TreeNode* root =
      leetcode::constructTree(std::vector<int>{3, 9});
  EXPECT_EQ(9, solution_.sumOfLeftLeaves(root));
  delete root;
}

TEST_P(SumOfLeftLeavesTest, SelfAuthoredNoLeftLeaves) {
  TreeNode* root =
      leetcode::constructTree(std::vector<std::optional<int>>{3, std::nullopt, 20});
  EXPECT_EQ(0, solution_.sumOfLeftLeaves(root));
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    SumOfLeftLeavesTestSuite, SumOfLeftLeavesTest,
    ::testing::ValuesIn(SumOfLeftLeavesSolution().getStrategyNames()));

}  // namespace leetcode::problem_404
