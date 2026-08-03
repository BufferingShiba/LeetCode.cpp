#include <gtest/gtest.h>

#include "leetcode/problems/binary-tree-tilt.h"

using namespace leetcode;

class BinaryTreeTiltTest : public ::testing::TestWithParam<std::string> {
 protected:
  problem_563::BinaryTreeTiltSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(BinaryTreeTiltTest, Example1) {
  auto root = constructTree(std::vector<int>{1, 2, 3});
  EXPECT_EQ(solution.findTilt(root), 1);
}

TEST_P(BinaryTreeTiltTest, Example2) {
  auto root = constructTree(
      std::vector<std::optional<int>>{4, 2, 9, 3, 5, std::nullopt, 7});
  EXPECT_EQ(solution.findTilt(root), 15);
}

TEST_P(BinaryTreeTiltTest, Example3) {
  auto root = constructTree(std::vector<int>{21, 7, 14, 1, 1, 2, 2, 3, 3});
  EXPECT_EQ(solution.findTilt(root), 9);
}

TEST_P(BinaryTreeTiltTest, SelfAuthoredEmptyTree) {
  EXPECT_EQ(solution.findTilt(nullptr), 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, BinaryTreeTiltTest,
    ::testing::ValuesIn(problem_563::BinaryTreeTiltSolution().getStrategyNames()));
