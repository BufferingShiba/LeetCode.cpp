#include "leetcode/problems/smallest-subarrays-with-maximum-bitwise-or.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_2411 {

class SmallestSubarraysWithMaximumBitwiseOrTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SmallestSubarraysWithMaximumBitwiseOrSolution solution;
};

TEST_P(SmallestSubarraysWithMaximumBitwiseOrTest, Example1) {
  std::vector<int> nums = {1, 0, 2, 1, 3};
  std::vector<int> expected = {3, 3, 2, 2, 1};
  EXPECT_EQ(solution.smallestSubarrays(nums), expected);
}

TEST_P(SmallestSubarraysWithMaximumBitwiseOrTest, Example2) {
  std::vector<int> nums = {1, 2};
  std::vector<int> expected = {2, 1};
  EXPECT_EQ(solution.smallestSubarrays(nums), expected);
}

TEST_P(SmallestSubarraysWithMaximumBitwiseOrTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  std::vector<int> expected = {1};
  EXPECT_EQ(solution.smallestSubarrays(nums), expected);
}

TEST_P(SmallestSubarraysWithMaximumBitwiseOrTest, SelfAuthoredAllZeros) {
  std::vector<int> nums = {0, 0, 0};
  // 每个后缀最大 OR = 0，最短子数组长度为 1
  std::vector<int> expected = {1, 1, 1};
  EXPECT_EQ(solution.smallestSubarrays(nums), expected);
}

TEST_P(SmallestSubarraysWithMaximumBitwiseOrTest, SelfAuthoredDecreasingRequiredLength) {
  // 从 index 0 需要覆盖两个不同 high bit，由末尾提供
  std::vector<int> nums = {1, 0, 4};
  // suffixOr[0] = 1|0|4 = 5; 最近提供 bit0 在 0, bit2 在 2 → 长度 3
  // suffixOr[1] = 0|4 = 4; 长度 2
  // suffixOr[2] = 4; 长度 1
  std::vector<int> expected = {3, 2, 1};
  EXPECT_EQ(solution.smallestSubarrays(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    SmallestSubarraysWithMaximumBitwiseOrTestCases,
    SmallestSubarraysWithMaximumBitwiseOrTest,
    ::testing::ValuesIn(
        SmallestSubarraysWithMaximumBitwiseOrSolution().getStrategyNames()));

}  // namespace problem_2411
}  // namespace leetcode
