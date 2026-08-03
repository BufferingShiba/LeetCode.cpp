#include <gtest/gtest.h>

#include "leetcode/problems/path-in-zigzag-labelled-binary-tree.h"

namespace leetcode::problem_1104 {

class PathInZigzagLabelledBinaryTreeTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PathInZigzagLabelledBinaryTreeSolution solution;
};

TEST_P(PathInZigzagLabelledBinaryTreeTest, OfficialExample1) {
  std::vector<int> expected{1, 3, 4, 14};
  EXPECT_EQ(solution.pathInZigZagTree(14), expected);
}

TEST_P(PathInZigzagLabelledBinaryTreeTest, OfficialExample2) {
  std::vector<int> expected{1, 2, 6, 10, 26};
  EXPECT_EQ(solution.pathInZigZagTree(26), expected);
}

TEST_P(PathInZigzagLabelledBinaryTreeTest, SelfAuthoredRootOnly) {
  std::vector<int> expected{1};
  EXPECT_EQ(solution.pathInZigZagTree(1), expected);
}

TEST_P(PathInZigzagLabelledBinaryTreeTest, SelfAuthoredEdgeLabelAtLevelStart) {
  // Level 3 (odd), first element = 4
  // Path: 1 -> 3 -> 4 (even level 2: 3 is 2nd from right; level 3: 4 is 1st from left)
  std::vector<int> expected{1, 3, 4};
  EXPECT_EQ(solution.pathInZigZagTree(4), expected);
}

TEST_P(PathInZigzagLabelledBinaryTreeTest, SelfAuthoredEdgeLabelAtLevelEnd) {
  // Level 3, last element = 7
  std::vector<int> expected{1, 2, 7};
  EXPECT_EQ(solution.pathInZigZagTree(7), expected);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    PathInZigzagLabelledBinaryTreeTest,
    testing::ValuesIn(
        PathInZigzagLabelledBinaryTreeSolution().getStrategyNames()));

}  // namespace leetcode::problem_1104
