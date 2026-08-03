#include <gtest/gtest.h>
#include "leetcode/problems/count-stable-subarrays.h"

using namespace leetcode::problem_3748;

class CountStableSubarraysTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
  CountStableSubarraysSolution solution;
};

TEST_P(CountStableSubarraysTest, Example1) {
  std::vector<int> nums = {3, 1, 2};
  std::vector<std::vector<int>> queries = {{0, 1}, {1, 2}, {0, 2}};
  std::vector<long long> expected = {2, 3, 4};
  EXPECT_EQ(solution.countStableSubarrays(nums, queries), expected);
}

TEST_P(CountStableSubarraysTest, Example2) {
  std::vector<int> nums = {2, 2};
  std::vector<std::vector<int>> queries = {{0, 1}, {0, 0}};
  std::vector<long long> expected = {3, 1};
  EXPECT_EQ(solution.countStableSubarrays(nums, queries), expected);
}

TEST_P(CountStableSubarraysTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  std::vector<std::vector<int>> queries = {{0, 0}};
  std::vector<long long> expected = {1};
  EXPECT_EQ(solution.countStableSubarrays(nums, queries), expected);
}

TEST_P(CountStableSubarraysTest, SelfAuthoredAllDecreasing) {
  std::vector<int> nums = {5, 4, 3, 2, 1};
  std::vector<std::vector<int>> queries = {{0, 4}, {0, 0}, {1, 3}};
  std::vector<long long> expected = {5, 1, 3};
  EXPECT_EQ(solution.countStableSubarrays(nums, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    CountStableSubarrays,
    CountStableSubarraysTest,
    testing::ValuesIn(CountStableSubarraysSolution().getStrategyNames()));
