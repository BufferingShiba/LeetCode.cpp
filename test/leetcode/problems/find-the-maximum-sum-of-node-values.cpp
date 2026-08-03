#include <gtest/gtest.h>

#include "leetcode/problems/find-the-maximum-sum-of-node-values.h"

using namespace leetcode::problem_3068;

class FindTheMaximumSumOfNodeValuesTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  FindTheMaximumSumOfNodeValuesSolution solution;
};

TEST_P(FindTheMaximumSumOfNodeValuesTest, OfficialExample1) {
  std::vector<int> nums = {1, 2, 1};
  int k = 3;
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}};
  EXPECT_EQ(solution.maximumValueSum(nums, k, edges), 6);
}

TEST_P(FindTheMaximumSumOfNodeValuesTest, OfficialExample2) {
  std::vector<int> nums = {2, 3};
  int k = 7;
  std::vector<std::vector<int>> edges = {{0, 1}};
  EXPECT_EQ(solution.maximumValueSum(nums, k, edges), 9);
}

TEST_P(FindTheMaximumSumOfNodeValuesTest, OfficialExample3) {
  std::vector<int> nums = {7, 7, 7, 7, 7, 7};
  int k = 3;
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}};
  EXPECT_EQ(solution.maximumValueSum(nums, k, edges), 42);
}

TEST_P(FindTheMaximumSumOfNodeValuesTest, SelfAuthoredOddPositiveCount) {
  // nums = [1, 5, 5], k = 7
  // deltas: +5, -3, -3 → one positive (odd)
  // drop +5 → sum = 11; pair +5 with -3 → sum = 13
  std::vector<int> nums = {1, 5, 5};
  int k = 7;
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}};
  EXPECT_EQ(solution.maximumValueSum(nums, k, edges), 13);
}

TEST_P(FindTheMaximumSumOfNodeValuesTest, SelfAuthoredAllPositiveOddCount) {
  // All deltas positive, odd count → must drop smallest positive
  // nums = [1, 1, 1], k = 7: deltas: 1^7=6 delta=+5 each, all positive, count=3 (odd)
  // sum_nums=3, pos_sum=15, min_pos=5 → drop smallest: 3+10=13
  std::vector<int> nums = {1, 1, 1};
  int k = 7;
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}};
  EXPECT_EQ(solution.maximumValueSum(nums, k, edges), 13);
}

INSTANTIATE_TEST_SUITE_P(Strategies, FindTheMaximumSumOfNodeValuesTest,
                         testing::ValuesIn(FindTheMaximumSumOfNodeValuesSolution().getStrategyNames()));
