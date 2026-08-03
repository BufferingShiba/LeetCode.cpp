#include <gtest/gtest.h>

#include "leetcode/problems/minimum-operations-to-equalize-subarrays.h"

using namespace leetcode::problem_3762;

class MinimumOperationsToEqualizeSubarraysTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MinimumOperationsToEqualizeSubarraysSolution solution;
};

TEST_P(MinimumOperationsToEqualizeSubarraysTest, Example1) {
  std::vector<int> nums = {1, 4, 7};
  int k = 3;
  std::vector<std::vector<int>> queries = {{0, 1}, {0, 2}};
  std::vector<long long> expected = {1, 2};
  EXPECT_EQ(solution.minOperations(nums, k, queries), expected);
}

TEST_P(MinimumOperationsToEqualizeSubarraysTest, Example2) {
  std::vector<int> nums = {1, 2, 4};
  int k = 2;
  std::vector<std::vector<int>> queries = {{0, 2}, {0, 0}, {1, 2}};
  std::vector<long long> expected = {-1, 0, 1};
  EXPECT_EQ(solution.minOperations(nums, k, queries), expected);
}

TEST_P(MinimumOperationsToEqualizeSubarraysTest, SelfAuthoredSingleElementQueries) {
  std::vector<int> nums = {5, 10, 15};
  int k = 5;
  std::vector<std::vector<int>> queries = {{0, 0}, {1, 1}, {2, 2}};
  std::vector<long long> expected = {0, 0, 0};
  EXPECT_EQ(solution.minOperations(nums, k, queries), expected);
}

TEST_P(MinimumOperationsToEqualizeSubarraysTest, SelfAuthoredAllSameValue) {
  std::vector<int> nums = {7, 7, 7, 7};
  int k = 3;
  std::vector<std::vector<int>> queries = {{0, 3}, {1, 2}};
  std::vector<long long> expected = {0, 0};
  EXPECT_EQ(solution.minOperations(nums, k, queries), expected);
}

TEST_P(MinimumOperationsToEqualizeSubarraysTest, SelfAuthoredRemainderMismatch) {
  std::vector<int> nums = {1, 2, 3};
  int k = 2;
  // remainders: 1, 0, 1
  std::vector<std::vector<int>> queries = {{0, 1}, {1, 2}, {0, 2}};
  std::vector<long long> expected = {-1, -1, -1};
  EXPECT_EQ(solution.minOperations(nums, k, queries), expected);
}

TEST_P(MinimumOperationsToEqualizeSubarraysTest, SelfAuthoredKEqualsOne) {
  std::vector<int> nums = {100, 200, 150};
  int k = 1;
  // always possible, median of [100,200,150] is 150
  // |100-150| + |200-150| + |150-150| = 50 + 50 + 0 = 100
  std::vector<std::vector<int>> queries = {{0, 2}};
  std::vector<long long> expected = {100};
  EXPECT_EQ(solution.minOperations(nums, k, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(Strategies, MinimumOperationsToEqualizeSubarraysTest,
                         testing::ValuesIn(MinimumOperationsToEqualizeSubarraysSolution()
                                               .getStrategyNames()));
