#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-operations-to-make-array-sum-divisible-by-k.h"

namespace leetcode {
namespace problem_3512 {

using MinimumOperationsToMakeArraySumDivisibleByKTest =
    ::testing::TestWithParam<std::string>;

class MinimumOperationsToMakeArraySumDivisibleByKFixture
    : public MinimumOperationsToMakeArraySumDivisibleByKTest {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MinimumOperationsToMakeArraySumDivisibleByKSolution solution_;
};

TEST_P(MinimumOperationsToMakeArraySumDivisibleByKFixture, Example1) {
  std::vector<int> nums = {3, 9, 7};
  EXPECT_EQ(solution_.minOperations(nums, 5), 4);
}

TEST_P(MinimumOperationsToMakeArraySumDivisibleByKFixture, Example2) {
  std::vector<int> nums = {4, 1, 3};
  EXPECT_EQ(solution_.minOperations(nums, 4), 0);
}

TEST_P(MinimumOperationsToMakeArraySumDivisibleByKFixture, Example3) {
  std::vector<int> nums = {3, 2};
  EXPECT_EQ(solution_.minOperations(nums, 6), 5);
}

TEST_P(MinimumOperationsToMakeArraySumDivisibleByKFixture, SelfAuthoredSingleElementDivisible) {
  std::vector<int> nums = {10};
  EXPECT_EQ(solution_.minOperations(nums, 5), 0);
}

TEST_P(MinimumOperationsToMakeArraySumDivisibleByKFixture, SelfAuthoredDivisibleAlready) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(solution_.minOperations(nums, 5), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumOperationsToMakeArraySumDivisibleByKTests,
    MinimumOperationsToMakeArraySumDivisibleByKFixture,
    ::testing::ValuesIn(
        MinimumOperationsToMakeArraySumDivisibleByKSolution().getStrategyNames()));

}  // namespace problem_3512
}  // namespace leetcode
