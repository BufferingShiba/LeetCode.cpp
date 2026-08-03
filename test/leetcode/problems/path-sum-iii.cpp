#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/path-sum-iii.h"
#include "leetcode/utils/tree.h"

namespace leetcode::problem_437 {
namespace {

using leetcode::TreeNode;

}  // namespace

class PathSumIiiTest : public ::testing::TestWithParam<std::string> {
 protected:
  PathSumIiiSolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(PathSumIiiTest, Example1) {
  TreeNode* root =
      leetcode::constructTree(std::vector<int>{10, 5, -3, 3, 2, -1, 11, 3,
                                               -2, -1, 1});
  EXPECT_EQ(solution.pathSum(root, 8), 3);
  delete root;
}

TEST_P(PathSumIiiTest, Example2) {
  TreeNode* root =
      leetcode::constructTree(std::vector<int>{5, 4, 8, 11, -1, 13, 4, 7, 2,
                                               -1, -1, 5, 1});
  EXPECT_EQ(solution.pathSum(root, 22), 3);
  delete root;
}

TEST_P(PathSumIiiTest, SelfAuthoredSingleNodeMatch) {
  TreeNode* root = leetcode::constructTree(std::vector<int>{1});
  EXPECT_EQ(solution.pathSum(root, 1), 1);
  delete root;
}

TEST_P(PathSumIiiTest, SelfAuthoredSingleNodeNoMatch) {
  TreeNode* root = leetcode::constructTree(std::vector<int>{1});
  EXPECT_EQ(solution.pathSum(root, 0), 0);
  delete root;
}

TEST_P(PathSumIiiTest, SelfAuthoredEmptyTree) {
  EXPECT_EQ(solution.pathSum(nullptr, 0), 0);
}

TEST_P(PathSumIiiTest, SelfAuthoredZeroTargetSkips) {
  // root = [1, -2], targetSum = -1 -> path [1 -> -2] sums to -1, and node -2 alone.
  TreeNode* root = leetcode::constructTree(std::vector<int>{1, -2, -1});
  // Paths: 1 + (-2) = -1 (from root to left child), and -2 alone does not equal
  // -1? node -2 != -1. So answer 1.
  EXPECT_EQ(solution.pathSum(root, -1), 1);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    PathSumIiiTestSuite, PathSumIiiTest,
    ::testing::ValuesIn(PathSumIiiSolution().getStrategyNames()));

}  // namespace leetcode::problem_437
