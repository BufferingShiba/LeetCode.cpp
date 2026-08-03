#include "leetcode/problems/construct-string-from-binary-tree.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_606 {

class ConstructStringFromBinaryTreeTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ConstructStringFromBinaryTreeSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  root = [1,2,3,4]
// Output: "1(2(4))(3)"
TEST_P(ConstructStringFromBinaryTreeTest, OfficialExample1) {
  TreeNode* root = leetcode::constructTree(std::vector<int>{1, 2, 3, 4});
  EXPECT_EQ(solution.tree2str(root), "1(2(4))(3)");
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  root = [1,2,3,null,4]
// Output: "1(2()(4))(3)"
TEST_P(ConstructStringFromBinaryTreeTest, OfficialExample2) {
  TreeNode* root = leetcode::constructTree(std::vector<int>{1, 2, 3, -1, 4});
  EXPECT_EQ(solution.tree2str(root), "1(2()(4))(3)");
}

// ===== Single Node =====
TEST_P(ConstructStringFromBinaryTreeTest, SingleNode) {
  TreeNode* root = leetcode::constructTree(std::vector<int>{5});
  EXPECT_EQ(solution.tree2str(root), "5");
}

// ===== Left child only =====
TEST_P(ConstructStringFromBinaryTreeTest, LeftChildOnly) {
  TreeNode* root = leetcode::constructTree(std::vector<int>{1, 2, -1});
  EXPECT_EQ(solution.tree2str(root), "1(2)");
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, ConstructStringFromBinaryTreeTest,
    ::testing::ValuesIn(ConstructStringFromBinaryTreeSolution().getStrategyNames()));

}  // namespace problem_606
}  // namespace leetcode
