#include "leetcode/problems/construct-the-minimum-bitwise-array-ii.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3315 {

class ConstructTheMinimumBitwiseArrayIiTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ConstructTheMinimumBitwiseArrayIiSolution solution;
};

TEST_P(ConstructTheMinimumBitwiseArrayIiTest, Example1) {
  vector<int> nums = {2, 3, 5, 7};
  vector<int> expected = {-1, 1, 4, 3};
  vector<int> result = solution.minBitwiseArray(nums);
  EXPECT_EQ(expected, result);
}

TEST_P(ConstructTheMinimumBitwiseArrayIiTest, Example2) {
  vector<int> nums = {11, 13, 31};
  vector<int> expected = {9, 12, 15};
  vector<int> result = solution.minBitwiseArray(nums);
  EXPECT_EQ(expected, result);
}

TEST_P(ConstructTheMinimumBitwiseArrayIiTest, AdditionalTest1) {
  vector<int> nums = {2};
  vector<int> expected = {-1};
  vector<int> result = solution.minBitwiseArray(nums);
  EXPECT_EQ(expected, result);
}

TEST_P(ConstructTheMinimumBitwiseArrayIiTest, AdditionalTest2) {
  vector<int> nums = {3};
  vector<int> expected = {1};
  vector<int> result = solution.minBitwiseArray(nums);
  EXPECT_EQ(expected, result);
}

TEST_P(ConstructTheMinimumBitwiseArrayIiTest, AdditionalTest3) {
  vector<int> nums = {5};
  vector<int> expected = {4};
  vector<int> result = solution.minBitwiseArray(nums);
  EXPECT_EQ(expected, result);
}

TEST_P(ConstructTheMinimumBitwiseArrayIiTest, AdditionalTest4) {
  vector<int> nums = {7};
  vector<int> expected = {3};
  vector<int> result = solution.minBitwiseArray(nums);
  EXPECT_EQ(expected, result);
}

TEST_P(ConstructTheMinimumBitwiseArrayIiTest, AdditionalTest5) {
  vector<int> nums = {131};  // 10000011 binary
  // 后缀连续1的个数：最低位1，次低位1，第三位0 -> suffix_ones = 2
  // ans = 131 - (1 << 1) = 131 - 2 = 129
  // 验证：129 (10000001) OR 130 (10000010) = 131 (10000011)
  vector<int> expected = {129};
  vector<int> result = solution.minBitwiseArray(nums);
  EXPECT_EQ(expected, result);
}

TEST_P(ConstructTheMinimumBitwiseArrayIiTest, AdditionalTest6) {
  vector<int> nums = {257};  // 100000001 binary
  // 后缀连续1的个数：最低位1，次低位0 -> suffix_ones = 1
  // ans = 257 - 1 = 256
  // 验证：256 (100000000) OR 257 (100000001) = 257
  vector<int> expected = {256};
  vector<int> result = solution.minBitwiseArray(nums);
  EXPECT_EQ(expected, result);
}

TEST_P(ConstructTheMinimumBitwiseArrayIiTest, AdditionalTest7) {
  vector<int> nums = {1023}; // 1111111111 (10 bits)
  // 后缀连续1的个数 = 10
  // ans = 1023 - (1 << 9) = 1023 - 512 = 511
  // 验证：511 (0111111111) OR 512 (1000000000) = 1023 (1111111111)
  vector<int> expected = {511};
  vector<int> result = solution.minBitwiseArray(nums);
  EXPECT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, ConstructTheMinimumBitwiseArrayIiTest,
    ::testing::ValuesIn(ConstructTheMinimumBitwiseArrayIiSolution().getStrategyNames()));

}  // namespace problem_3315
}  // namespace leetcode