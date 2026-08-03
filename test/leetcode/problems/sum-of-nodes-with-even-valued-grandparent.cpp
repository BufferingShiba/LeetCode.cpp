#include "leetcode/problems/sum-of-nodes-with-even-valued-grandparent.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1315 {

class SumOfNodesWithEvenValuedGrandparentTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SumOfNodesWithEvenValuedGrandparentSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
// Output: 18
TEST_P(SumOfNodesWithEvenValuedGrandparentTest, OfficialExample1) {
  TreeNode* root =
      leetcode::constructTree(std::vector<int>{6, 7, 8, 2, 7, 1, 3, 9, -1, 1, 4, -1, -1, -1, 5});
  EXPECT_EQ(18, solution.sumEvenGrandparent(root));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  root = [1]
// Output: 0
TEST_P(SumOfNodesWithEvenValuedGrandparentTest, OfficialExample2) {
  TreeNode* root = leetcode::constructTree(std::vector<int>{1});
  EXPECT_EQ(0, solution.sumEvenGrandparent(root));
}

// ===== SelfAuthored: small tree with all grandchildren of even-valued root =====
// root=2: left child=4, 4->its child (left subchild) has grandparent=2 (even).
TEST_P(SumOfNodesWithEvenValuedGrandparentTest, SelfAuthoredEvenRoot) {
  // Tree:
  //        2
  //       / \
  //      4   6
  //     /     \
  //    1       3
  // Nodes with even grandparent: 1 (grandparent 2, even), 3 (grandparent 2, even).
  // Node 4's grandparent is null; node 6's grandparent is null.
  TreeNode* root = leetcode::constructTree(std::vector<int>{2, 4, 6, 1, -1, -1, 3});
  EXPECT_EQ(4, solution.sumEvenGrandparent(root));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, SumOfNodesWithEvenValuedGrandparentTest,
    ::testing::ValuesIn(SumOfNodesWithEvenValuedGrandparentSolution().getStrategyNames()));

}  // namespace problem_1315
}  // namespace leetcode
