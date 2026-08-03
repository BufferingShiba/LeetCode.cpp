#include <gtest/gtest.h>

#include <optional>
#include <vector>

#include "leetcode/problems/leaf-similar-trees.h"

using namespace leetcode;
using namespace leetcode::problem_872;

class LeafSimilarTreesTest : public testing::TestWithParam<std::string> {
 protected:
  LeafSimilarTreesSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(LeafSimilarTreesTest, Example1) {
  auto* root1 = constructTree(std::vector<std::optional<int>>{
      3, 5, 1, 6, 2, 9, 8, std::nullopt, std::nullopt, 7, 4});
  auto* root2 = constructTree(std::vector<std::optional<int>>{
      3, 5, 1, 6, 7, 4, 2, std::nullopt, std::nullopt, std::nullopt,
      std::nullopt, std::nullopt, std::nullopt, 9, 8});
  EXPECT_TRUE(solution.leafSimilar(root1, root2));
  delete root1;
  delete root2;
}

TEST_P(LeafSimilarTreesTest, Example2) {
  auto* root1 = constructTree(std::vector<int>{1, 2, 3});
  auto* root2 = constructTree(std::vector<int>{1, 3, 2});
  EXPECT_FALSE(solution.leafSimilar(root1, root2));
  delete root1;
  delete root2;
}

INSTANTIATE_TEST_SUITE_P(Strategies, LeafSimilarTreesTest,
                         testing::ValuesIn(
                             LeafSimilarTreesSolution().getStrategyNames()));
