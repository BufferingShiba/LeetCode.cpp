#include "leetcode/problems/partition-equal-subset-sum.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_416 {

class PartitionEqualSubsetSumTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PartitionEqualSubsetSumSolution solution;
};

INSTANTIATE_TEST_SUITE_P(
    LeetCode, PartitionEqualSubsetSumTest,
    ::testing::ValuesIn(PartitionEqualSubsetSumSolution().getStrategyNames()));

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [1,5,11,5]
// Output: true
TEST_P(PartitionEqualSubsetSumTest, OfficialExample1) {
  std::vector<int> nums = {1, 5, 11, 5};
  EXPECT_EQ(solution.canPartition(nums), true);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [1,2,3,5]
// Output: false
TEST_P(PartitionEqualSubsetSumTest, OfficialExample2) {
  std::vector<int> nums = {1, 2, 3, 5};
  EXPECT_EQ(solution.canPartition(nums), false);
}

// ===== Edge case: single element, odd total => false =====
TEST_P(PartitionEqualSubsetSumTest, SingleElementOdd) {
  std::vector<int> nums = {3};
  EXPECT_EQ(solution.canPartition(nums), false);
}

// ===== Edge case: total is odd => false =====
TEST_P(PartitionEqualSubsetSumTest, OddTotal) {
  std::vector<int> nums = {1, 2, 5};
  EXPECT_EQ(solution.canPartition(nums), false);
}

// ===== Edge case: two identical elements => true =====
TEST_P(PartitionEqualSubsetSumTest, TwoIdenticalElements) {
  std::vector<int> nums = {5, 5};
  EXPECT_EQ(solution.canPartition(nums), true);
}

}  // namespace problem_416
}  // namespace leetcode
