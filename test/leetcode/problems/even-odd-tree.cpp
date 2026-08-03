#include <gtest/gtest.h>

#include "leetcode/problems/even-odd-tree.h"

using namespace leetcode::problem_1609;

class EvenOddTreeTest : public ::testing::TestWithParam<std::string> {
 protected:
  EvenOddTreeSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(EvenOddTreeTest, Example1) {
  auto* root = leetcode::constructTree(
      std::vector<int>{1, 10, 4, 3, -1, 7, 9, 12, 8, 6, -1, -1, 2});
  EXPECT_TRUE(solution.isEvenOddTree(root));
  delete root;
}

TEST_P(EvenOddTreeTest, Example2) {
  auto* root = leetcode::constructTree(std::vector<int>{5, 4, 2, 3, 3, 7});
  EXPECT_FALSE(solution.isEvenOddTree(root));
  delete root;
}

TEST_P(EvenOddTreeTest, Example3) {
  auto* root = leetcode::constructTree(std::vector<int>{5, 9, 1, 3, 5, 7});
  EXPECT_FALSE(solution.isEvenOddTree(root));
  delete root;
}

INSTANTIATE_TEST_SUITE_P(AllStrategies, EvenOddTreeTest,
                         ::testing::ValuesIn(EvenOddTreeSolution().getStrategyNames()));
