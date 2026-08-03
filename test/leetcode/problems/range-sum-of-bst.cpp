#include <gtest/gtest.h>

#include "leetcode/problems/range-sum-of-bst.h"

namespace leetcode {
namespace problem_938 {

class RangeSumOfBstTest : public ::testing::TestWithParam<std::string> {
 protected:
  RangeSumOfBstSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(RangeSumOfBstTest, Example1) {
  TreeNode* root =
      constructTree(std::vector<std::optional<int>>{10, 5, 15, 3, 7,
                                                      std::nullopt, 18});
  EXPECT_EQ(solution.rangeSumBST(root, 7, 15), 32);
}

TEST_P(RangeSumOfBstTest, Example2) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{
      10, 5, 15, 3, 7, 13, 18, 1, std::nullopt, 6});
  EXPECT_EQ(solution.rangeSumBST(root, 6, 10), 23);
}

TEST_P(RangeSumOfBstTest, SelfAuthoredAllInRange) {
  // 单节点树，区间覆盖该节点
  TreeNode* root = constructTree(std::vector<int>{10});
  EXPECT_EQ(solution.rangeSumBST(root, 1, 20), 10);
}

TEST_P(RangeSumOfBstTest, SelfAuthoredNoneInRange) {
  // 区间完全落在节点值之外
  TreeNode* root =
      constructTree(std::vector<std::optional<int>>{10, 5, 15, 3, 7,
                                                      std::nullopt, 18});
  EXPECT_EQ(solution.rangeSumBST(root, 20, 30), 0);
}

INSTANTIATE_TEST_SUITE_P(, RangeSumOfBstTest,
                         ::testing::ValuesIn(
                             RangeSumOfBstSolution().getStrategyNames()));

}  // namespace problem_938
}  // namespace leetcode
