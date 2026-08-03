#include <gtest/gtest.h>

#include "leetcode/problems/minimum-absolute-difference-queries.h"

using namespace leetcode::problem_1906;

class MinimumAbsoluteDifferenceQueriesTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  MinimumAbsoluteDifferenceQueriesSolution solution_;
};

TEST_P(MinimumAbsoluteDifferenceQueriesTest, Example1) {
  std::vector<int> nums = {1, 3, 4, 8};
  std::vector<std::vector<int>> queries = {{0, 1}, {1, 2}, {2, 3}, {0, 3}};
  std::vector<int> expected = {2, 1, 4, 1};
  EXPECT_EQ(solution_.minDifference(nums, queries), expected);
}

TEST_P(MinimumAbsoluteDifferenceQueriesTest, Example2) {
  std::vector<int> nums = {4, 5, 2, 2, 7, 10};
  std::vector<std::vector<int>> queries = {{2, 3}, {0, 2}, {0, 5}, {3, 5}};
  std::vector<int> expected = {-1, 1, 1, 3};
  EXPECT_EQ(solution_.minDifference(nums, queries), expected);
}

TEST_P(MinimumAbsoluteDifferenceQueriesTest, SelfAuthoredSinglePairSameElement) {
  std::vector<int> nums = {5, 5};
  std::vector<std::vector<int>> queries = {{0, 1}};
  std::vector<int> expected = {-1};
  EXPECT_EQ(solution_.minDifference(nums, queries), expected);
}

TEST_P(MinimumAbsoluteDifferenceQueriesTest, SelfAuthoredAllDistinct) {
  std::vector<int> nums = {10, 20, 30, 40};
  std::vector<std::vector<int>> queries = {{0, 3}};
  std::vector<int> expected = {10};
  EXPECT_EQ(solution_.minDifference(nums, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    MinimumAbsoluteDifferenceQueriesTest,
    testing::ValuesIn(MinimumAbsoluteDifferenceQueriesSolution().getStrategyNames()));
