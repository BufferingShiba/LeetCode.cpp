#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/average-of-levels-in-binary-tree.h"

using namespace leetcode;
using namespace leetcode::problem_637;

class AverageOfLevelsInBinaryTreeTest
    : public testing::TestWithParam<std::string> {
 protected:
  AverageOfLevelsInBinaryTreeSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(AverageOfLevelsInBinaryTreeTest, Example1) {
  auto* root = constructTree(
      std::vector<int>{3, 9, 20, -1, -1, 15, 7});
  std::vector<double> expected = {3.0, 14.5, 11.0};
  auto result = solution.averageOfLevels(root);
  ASSERT_EQ(result.size(), expected.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    EXPECT_NEAR(result[i], expected[i], 1e-5);
  }
  delete root;
}

TEST_P(AverageOfLevelsInBinaryTreeTest, Example2) {
  auto* root = constructTree(
      std::vector<int>{3, 9, 20, 15, 7});
  std::vector<double> expected = {3.0, 14.5, 11.0};
  auto result = solution.averageOfLevels(root);
  ASSERT_EQ(result.size(), expected.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    EXPECT_NEAR(result[i], expected[i], 1e-5);
  }
  delete root;
}

TEST_P(AverageOfLevelsInBinaryTreeTest, SelfAuthoredSingleNode) {
  auto* root = constructTree(std::vector<int>{42});
  std::vector<double> expected = {42.0};
  auto result = solution.averageOfLevels(root);
  ASSERT_EQ(result.size(), expected.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    EXPECT_NEAR(result[i], expected[i], 1e-5);
  }
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, AverageOfLevelsInBinaryTreeTest,
    testing::ValuesIn(AverageOfLevelsInBinaryTreeSolution().getStrategyNames()));
