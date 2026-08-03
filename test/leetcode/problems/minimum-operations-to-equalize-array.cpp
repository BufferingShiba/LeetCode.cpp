#include <gtest/gtest.h>

#include "leetcode/problems/minimum-operations-to-equalize-array.h"

namespace leetcode {
namespace problem_3674 {

class MinimumOperationsToEqualizeArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  MinimumOperationsToEqualizeArraySolution solution_;
};

TEST_P(MinimumOperationsToEqualizeArrayTest, Example1) {
  std::vector<int> nums = {1, 2};
  EXPECT_EQ(solution_.minOperations(nums), 1);
}

TEST_P(MinimumOperationsToEqualizeArrayTest, Example2) {
  std::vector<int> nums = {5, 5, 5};
  EXPECT_EQ(solution_.minOperations(nums), 0);
}

TEST_P(MinimumOperationsToEqualizeArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {42};
  EXPECT_EQ(solution_.minOperations(nums), 0);
}

TEST_P(MinimumOperationsToEqualizeArrayTest, SelfAuthoredAllDifferent) {
  std::vector<int> nums = {1, 3, 7, 15};
  EXPECT_EQ(solution_.minOperations(nums), 1);
}

TEST_P(MinimumOperationsToEqualizeArrayTest, SelfAuthoredTwoSameOneDifferent) {
  std::vector<int> nums = {7, 7, 5};
  EXPECT_EQ(solution_.minOperations(nums), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumOperationsToEqualizeArrayTest,
    ::testing::ValuesIn(
        MinimumOperationsToEqualizeArraySolution().getStrategyNames()));

}  // namespace problem_3674
}  // namespace leetcode
