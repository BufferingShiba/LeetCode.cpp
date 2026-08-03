#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "leetcode/problems/most-frequent-subtree-sum.h"

using namespace leetcode;
using namespace leetcode::problem_508;

class MostFrequentSubtreeSumTest
    : public testing::TestWithParam<std::string> {
 protected:
  MostFrequentSubtreeSumSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MostFrequentSubtreeSumTest, Example1) {
  TreeNode* root = constructTree(std::vector<int>{5, 2, -3});
  auto result = solution.findFrequentTreeSum(root);
  std::vector<int> expected = {2, -3, 4};
  std::sort(result.begin(), result.end());
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(result, expected);
  delete root;
}

TEST_P(MostFrequentSubtreeSumTest, Example2) {
  TreeNode* root = constructTree(std::vector<int>{5, 2, -5});
  auto result = solution.findFrequentTreeSum(root);
  std::vector<int> expected = {2};
  std::sort(result.begin(), result.end());
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(result, expected);
  delete root;
}

TEST_P(MostFrequentSubtreeSumTest, SelfAuthoredSingleNode) {
  TreeNode* root = constructTree(std::vector<int>{7});
  auto result = solution.findFrequentTreeSum(root);
  std::vector<int> expected = {7};
  EXPECT_EQ(result, expected);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MostFrequentSubtreeSumTest,
    testing::ValuesIn(MostFrequentSubtreeSumSolution().getStrategyNames()));
