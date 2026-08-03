#include "leetcode/problems/sum-of-values-at-indices-with-k-set-bits.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2859 {

class SumOfValuesAtIndicesWithKSetBitsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SumOfValuesAtIndicesWithKSetBitsSolution solution;
};

INSTANTIATE_TEST_SUITE_P(
    LeetCode, SumOfValuesAtIndicesWithKSetBitsTest,
    ::testing::ValuesIn(SumOfValuesAtIndicesWithKSetBitsSolution().getStrategyNames()));

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [5,10,1,5,2], k = 1
// Output: 13
TEST_P(SumOfValuesAtIndicesWithKSetBitsTest, OfficialExample1) {
  std::vector<int> nums = {5, 10, 1, 5, 2};
  int k = 1;
  EXPECT_EQ(13, solution.sumIndicesWithKSetBits(nums, k));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [4,3,2,1], k = 2
// Output: 1
TEST_P(SumOfValuesAtIndicesWithKSetBitsTest, OfficialExample2) {
  std::vector<int> nums = {4, 3, 2, 1};
  int k = 2;
  EXPECT_EQ(1, solution.sumIndicesWithKSetBits(nums, k));
}

}  // namespace problem_2859
}  // namespace leetcode
