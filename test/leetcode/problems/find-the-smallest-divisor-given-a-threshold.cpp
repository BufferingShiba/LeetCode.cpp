#include <gtest/gtest.h>

#include "leetcode/problems/find-the-smallest-divisor-given-a-threshold.h"

namespace leetcode::problem_1283 {
namespace {

class FindTheSmallestDivisorGivenAThresholdTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheSmallestDivisorGivenAThresholdSolution solution;
};

TEST_P(FindTheSmallestDivisorGivenAThresholdTest, Example1) {
  std::vector<int> nums = {1, 2, 5, 9};
  int threshold = 6;
  EXPECT_EQ(solution.smallestDivisor(nums, threshold), 5);
}

TEST_P(FindTheSmallestDivisorGivenAThresholdTest, Example2) {
  std::vector<int> nums = {44, 22, 33, 11, 1};
  int threshold = 5;
  EXPECT_EQ(solution.smallestDivisor(nums, threshold), 44);
}

TEST_P(FindTheSmallestDivisorGivenAThresholdTest, SelfAuthored_AllOnes) {
  std::vector<int> nums = {1, 1, 1, 1};
  int threshold = 4;
  // divisor=1: sum=4 <= 4
  EXPECT_EQ(solution.smallestDivisor(nums, threshold), 1);
}

TEST_P(FindTheSmallestDivisorGivenAThresholdTest, SelfAuthored_SingleElement) {
  std::vector<int> nums = {100};
  int threshold = 1;
  // divisor must be >= 100 to make ceil(100/100)=1 <= 1
  EXPECT_EQ(solution.smallestDivisor(nums, threshold), 100);
}

TEST_P(FindTheSmallestDivisorGivenAThresholdTest, SelfAuthored_LargeDivisor) {
  std::vector<int> nums = {10, 10, 10};
  int threshold = 3;
  // divisor=10: ceil(10/10)=1 each, sum=3 <= 3
  EXPECT_EQ(solution.smallestDivisor(nums, threshold), 10);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindTheSmallestDivisorGivenAThresholdTest,
    testing::ValuesIn(FindTheSmallestDivisorGivenAThresholdSolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_1283
