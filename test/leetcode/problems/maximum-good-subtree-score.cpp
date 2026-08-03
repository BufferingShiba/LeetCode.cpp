#include "leetcode/problems/maximum-good-subtree-score.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3575 {
namespace {

class MaximumGoodSubtreeScoreTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MaximumGoodSubtreeScoreSolution solution;
};

TEST_P(MaximumGoodSubtreeScoreTest, Example1) {
  std::vector<int> vals = {2, 3};
  std::vector<int> par = {-1, 0};
  EXPECT_EQ(solution.getSolution()(vals, par), 8);
}

TEST_P(MaximumGoodSubtreeScoreTest, Example2) {
  std::vector<int> vals = {1, 5, 2};
  std::vector<int> par = {-1, 0, 0};
  EXPECT_EQ(solution.getSolution()(vals, par), 15);
}

TEST_P(MaximumGoodSubtreeScoreTest, Example3) {
  std::vector<int> vals = {34, 1, 2};
  std::vector<int> par = {-1, 0, 1};
  EXPECT_EQ(solution.getSolution()(vals, par), 42);
}

TEST_P(MaximumGoodSubtreeScoreTest, Example4) {
  std::vector<int> vals = {3, 22, 5};
  std::vector<int> par = {-1, 0, 1};
  EXPECT_EQ(solution.getSolution()(vals, par), 18);
}

TEST_P(MaximumGoodSubtreeScoreTest, SelfAuthoredSingleUniqueDigit) {
  std::vector<int> vals = {7};
  std::vector<int> par = {-1};
  EXPECT_EQ(solution.getSolution()(vals, par), 7);
}

TEST_P(MaximumGoodSubtreeScoreTest, SelfAuthoredSingleRepeatedDigit) {
  std::vector<int> vals = {11};
  std::vector<int> par = {-1};
  EXPECT_EQ(solution.getSolution()(vals, par), 0);
}

TEST_P(MaximumGoodSubtreeScoreTest, SelfAuthoredAllDigitsShared) {
  std::vector<int> vals = {6, 6, 6};
  std::vector<int> par = {-1, 0, 1};
  // 所有节点 digit 都是 6，同一 subset 内互斥，只能各自子树单独取。
  EXPECT_EQ(solution.getSolution()(vals, par), 18);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumGoodSubtreeScoreTestSuite, MaximumGoodSubtreeScoreTest,
    ::testing::ValuesIn(MaximumGoodSubtreeScoreSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3575
}  // namespace leetcode
