#include "leetcode/problems/deepest-leaves-sum.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1302 {

class DeepestLeavesSumTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DeepestLeavesSumSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
// Output: 15
TEST_P(DeepestLeavesSumTest, OfficialExample1) {
  TreeNode* root = leetcode::constructTree(std::vector<int>{1, 2, 3, 4, 5, -1, 6, 7, -1, -1, -1, -1, 8});
  EXPECT_EQ(15, solution.deepestLeavesSum(root));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
// Output: 19
TEST_P(DeepestLeavesSumTest, OfficialExample2) {
  TreeNode* root = leetcode::constructTree(std::vector<int>{6, 7, 8, 2, 7, 1, 3, 9, -1, 1, 4, -1, -1, -1, 5});
  EXPECT_EQ(19, solution.deepestLeavesSum(root));
}

// ===== Self-Authored: single node =====
// Input:  root = [1]
// Output: 1
TEST_P(DeepestLeavesSumTest, SingleNode) {
  TreeNode* root = leetcode::constructTree(std::vector<int>{1});
  EXPECT_EQ(1, solution.deepestLeavesSum(root));
}

// ===== Self-Authored: full balanced small tree, deepest leaves [4,5] =====
// Input:  root = [1,2,3,4,5]
// Output: 9
TEST_P(DeepestLeavesSumTest, FullBalancedTree) {
  TreeNode* root = leetcode::constructTree(std::vector<int>{1, 2, 3, 4, 5});
  EXPECT_EQ(9, solution.deepestLeavesSum(root));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, DeepestLeavesSumTest,
    ::testing::ValuesIn(DeepestLeavesSumSolution().getStrategyNames()));

}  // namespace problem_1302
}  // namespace leetcode
