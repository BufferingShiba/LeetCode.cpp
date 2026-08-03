#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-adjacent-swaps-to-partition-array.h"

namespace leetcode {
namespace problem_3994 {

class MinimumAdjacentSwapsToPartitionArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumAdjacentSwapsToPartitionArraySolution solution_;
};

TEST_P(MinimumAdjacentSwapsToPartitionArrayTest, Example1) {
  std::vector<int> nums = {1, 3, 2, 4, 5, 6};
  EXPECT_EQ(solution_.minAdjacentSwaps(nums, 3, 4), 1);
}

TEST_P(MinimumAdjacentSwapsToPartitionArrayTest, Example2) {
  std::vector<int> nums = {9, 7, 5, 3};
  EXPECT_EQ(solution_.minAdjacentSwaps(nums, 4, 8), 5);
}

TEST_P(MinimumAdjacentSwapsToPartitionArrayTest, Example3) {
  std::vector<int> nums = {3, 7, 5, 9};
  EXPECT_EQ(solution_.minAdjacentSwaps(nums, 4, 8), 0);
}

TEST_P(MinimumAdjacentSwapsToPartitionArrayTest, EmptyBorders) {
  // [1,2,3] all < a: already good; [5,6,7] all in [a,b]: already good.
  std::vector<int> nums = {1, 2, 3};
  EXPECT_EQ(solution_.minAdjacentSwaps(nums, 4, 8), 0);
  std::vector<int> nums2 = {5, 6, 7};
  EXPECT_EQ(solution_.minAdjacentSwaps(nums2, 4, 8), 0);
}

TEST_P(MinimumAdjacentSwapsToPartitionArrayTest, TailMustCrossAll) {
  // [9,1,1,1]: R L L L, R must cross all three L elements: 3 swaps.
  std::vector<int> nums = {9, 1, 1, 1};
  EXPECT_EQ(solution_.minAdjacentSwaps(nums, 4, 8), 3);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumAdjacentSwapsToPartitionArrayTests,
    MinimumAdjacentSwapsToPartitionArrayTest,
    ::testing::ValuesIn(
        MinimumAdjacentSwapsToPartitionArraySolution().getStrategyNames()));

}  // namespace problem_3994
}  // namespace leetcode
