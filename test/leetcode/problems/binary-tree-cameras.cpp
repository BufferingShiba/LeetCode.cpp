#include <gtest/gtest.h>

#include "leetcode/problems/binary-tree-cameras.h"

using namespace leetcode;
using namespace problem_968;

class BinaryTreeCamerasTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  BinaryTreeCamerasSolution solution_;
};

TEST_P(BinaryTreeCamerasTest, Example1) {
  auto* root = constructTree(std::vector<int>{0, 0, -1, 0, 0});
  EXPECT_EQ(solution_.minCameraCover(root), 1);
}

TEST_P(BinaryTreeCamerasTest, Example2) {
  auto* root =
      constructTree(std::vector<int>{0, 0, -1, 0, -1, 0, -1, -1, 0});
  EXPECT_EQ(solution_.minCameraCover(root), 2);
}

TEST_P(BinaryTreeCamerasTest, SelfAuthoredSingleNode) {
  auto* root = constructTree(std::vector<int>{0});
  EXPECT_EQ(solution_.minCameraCover(root), 1);
}

TEST_P(BinaryTreeCamerasTest, SelfAuthoredTwoNodes) {
  auto* root = constructTree(std::vector<int>{0, 0});
  EXPECT_EQ(solution_.minCameraCover(root), 1);
}

TEST_P(BinaryTreeCamerasTest, SelfAuthoredThreeNodesFull) {
  auto* root = constructTree(std::vector<int>{0, 0, 0});
  EXPECT_EQ(solution_.minCameraCover(root), 1);
}

TEST_P(BinaryTreeCamerasTest, SelfAuthoredLinearChain) {
  auto* root =
      constructTree(std::vector<int>{0, -1, 0, -1, -1, -1, 0});
  // Right-skewed chain of 3 nodes: root -> right -> right.
  // Optimal: camera at middle node covers all three.
  EXPECT_EQ(solution_.minCameraCover(root), 1);
}

INSTANTIATE_TEST_SUITE_P(AllStrategies, BinaryTreeCamerasTest,
                         testing::ValuesIn(BinaryTreeCamerasSolution()
                                                .getStrategyNames()));
