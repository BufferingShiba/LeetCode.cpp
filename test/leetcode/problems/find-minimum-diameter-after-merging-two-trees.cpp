#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-minimum-diameter-after-merging-two-trees.h"

namespace leetcode {
namespace problem_3203 {
namespace {

class FindMinimumDiameterAfterMergingTwoTreesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindMinimumDiameterAfterMergingTwoTreesSolution solution;
};

TEST_P(FindMinimumDiameterAfterMergingTwoTreesTest, Example1) {
  std::vector<std::vector<int>> edges1 = {{0, 1}, {0, 2}, {0, 3}};
  std::vector<std::vector<int>> edges2 = {{0, 1}};
  EXPECT_EQ(3, solution.getSolution()(edges1, edges2));
}

TEST_P(FindMinimumDiameterAfterMergingTwoTreesTest, Example2) {
  std::vector<std::vector<int>> edges1 = {
      {0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}};
  std::vector<std::vector<int>> edges2 = {
      {0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}};
  EXPECT_EQ(5, solution.getSolution()(edges1, edges2));
}

TEST_P(FindMinimumDiameterAfterMergingTwoTreesTest, SelfAuthoredSingleNodeEach) {
  std::vector<std::vector<int>> edges1 = {};
  std::vector<std::vector<int>> edges2 = {};
  EXPECT_EQ(1, solution.getSolution()(edges1, edges2));
}

TEST_P(FindMinimumDiameterAfterMergingTwoTreesTest, SelfAuthoredSingleNodeAndPath) {
  std::vector<std::vector<int>> edges1 = {};
  std::vector<std::vector<int>> edges2 = {{0, 1}, {1, 2}};
  // Tree2 diameter = 2 -> radius = 1; tree1 diameter = 0 -> radius = 0.
  // answer = max(0, 2, 0 + 1 + 1) = 2
  EXPECT_EQ(2, solution.getSolution()(edges1, edges2));
}

INSTANTIATE_TEST_SUITE_P(
    FindMinimumDiameterAfterMergingTwoTreesTestCases,
    FindMinimumDiameterAfterMergingTwoTreesTest,
    ::testing::ValuesIn(
        FindMinimumDiameterAfterMergingTwoTreesSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3203
}  // namespace leetcode
