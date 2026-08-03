#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-distance-between-bst-nodes.h"

namespace leetcode {
namespace problem_783 {

class MinimumDistanceBetweenBstNodesTest
    : public ::testing::TestWithParam<std::string> {
 public:
  void SetUp() override { solution_.setStrategy(GetParam()); }

 protected:
  MinimumDistanceBetweenBstNodesSolution solution_;
};

TEST_P(MinimumDistanceBetweenBstNodesTest, Example1) {
  TreeNode* root =
      constructTree(std::vector<std::optional<int>>{4, 2, 6, 1, 3});
  EXPECT_EQ(solution_.minDiffInBST(root), 1);
  delete root;
}

TEST_P(MinimumDistanceBetweenBstNodesTest, Example2) {
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{1, 0, 48, std::nullopt, std::nullopt,
                                      12, 49});
  EXPECT_EQ(solution_.minDiffInBST(root), 1);
  delete root;
}

TEST_P(MinimumDistanceBetweenBstNodesTest, SelfAuthoredTwoNodes) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{10, 5});
  EXPECT_EQ(solution_.minDiffInBST(root), 5);
  delete root;
}

TEST_P(MinimumDistanceBetweenBstNodesTest, SelfAuthoredThreeValues) {
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{3, 1, 5, std::nullopt, std::nullopt,
                                      std::nullopt, std::nullopt});
  EXPECT_EQ(solution_.minDiffInBST(root), 2);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    MinimumDistanceBetweenBstNodesTestSuite,
    MinimumDistanceBetweenBstNodesTest,
    ::testing::ValuesIn(
        MinimumDistanceBetweenBstNodesSolution().getStrategyNames()));

}  // namespace problem_783
}  // namespace leetcode
