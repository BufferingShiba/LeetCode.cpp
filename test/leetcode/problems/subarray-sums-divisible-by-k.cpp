#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/subarray-sums-divisible-by-k.h"

namespace leetcode {
namespace problem_974 {

class SubarraySumsDivisibleByKTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SubarraySumsDivisibleByKSolution solution;
};

TEST_P(SubarraySumsDivisibleByKTest, Example1) {
  std::vector<int> nums = {4, 5, 0, -2, -3, 1};
  int k = 5;
  EXPECT_EQ(solution.subarraysDivByK(nums, k), 7);
}

TEST_P(SubarraySumsDivisibleByKTest, Example2) {
  std::vector<int> nums = {5};
  int k = 9;
  EXPECT_EQ(solution.subarraysDivByK(nums, k), 0);
}

TEST_P(SubarraySumsDivisibleByKTest, SingleElementDivisible) {
  std::vector<int> nums = {10};
  int k = 5;
  EXPECT_EQ(solution.subarraysDivByK(nums, k), 1);
}

TEST_P(SubarraySumsDivisibleByKTest, AllZeros) {
  std::vector<int> nums = {0, 0, 0};
  int k = 5;
  // 所有子数组和均为 0，均可被 5 整除，共 6 个
  EXPECT_EQ(solution.subarraysDivByK(nums, k), 6);
}

TEST_P(SubarraySumsDivisibleByKTest, NegativeNumbers) {
  std::vector<int> nums = {-1, 2, 9};
  int k = 2;
  // 子数组: [2] sum=2, [-1,2,9] sum=10，都可被 2 整除
  EXPECT_EQ(solution.subarraysDivByK(nums, k), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    SubarraySumsDivisibleByKTest,
    testing::ValuesIn(SubarraySumsDivisibleByKSolution().getStrategyNames()));

}  // namespace problem_974
}  // namespace leetcode
