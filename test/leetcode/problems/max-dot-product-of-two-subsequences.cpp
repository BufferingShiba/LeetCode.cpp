#include "leetcode/problems/max-dot-product-of-two-subsequences.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1458 {

class MaxDotProductOfTwoSubsequencesTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaxDotProductOfTwoSubsequencesSolution solution;
};

TEST_P(MaxDotProductOfTwoSubsequencesTest, Example1) {
  vector<int> nums1 = {2, 1, -2, 5};
  vector<int> nums2 = {3, 0, -6};
  EXPECT_EQ(solution.maxDotProduct(nums1, nums2), 18);
}

TEST_P(MaxDotProductOfTwoSubsequencesTest, Example2) {
  vector<int> nums1 = {3, -2};
  vector<int> nums2 = {2, -6, 7};
  EXPECT_EQ(solution.maxDotProduct(nums1, nums2), 21);
}

TEST_P(MaxDotProductOfTwoSubsequencesTest, Example3) {
  vector<int> nums1 = {-1, -1};
  vector<int> nums2 = {1, 1};
  EXPECT_EQ(solution.maxDotProduct(nums1, nums2), -1);
}

TEST_P(MaxDotProductOfTwoSubsequencesTest, AllPositive) {
  vector<int> nums1 = {1, 2, 3};
  vector<int> nums2 = {4, 5, 6};
  // 最大点积：3*6 + 2*5 + 1*4 = 18+10+4=32
  EXPECT_EQ(solution.maxDotProduct(nums1, nums2), 32);
}

TEST_P(MaxDotProductOfTwoSubsequencesTest, AllNegative) {
  vector<int> nums1 = {-1, -2, -3};
  vector<int> nums2 = {-4, -5, -6};
  // 所有乘积都是正数，最大点积：(-1)*(-4) + (-2)*(-5) + (-3)*(-6) = 4+10+18=32
  EXPECT_EQ(solution.maxDotProduct(nums1, nums2), 32);
}

TEST_P(MaxDotProductOfTwoSubsequencesTest, MixedSigns) {
  vector<int> nums1 = {1, -2, 3};
  vector<int> nums2 = {-4, 5, -6};
  // 最佳配对：(-2)*(-4) + 3*5 = 8+15=23
  EXPECT_EQ(solution.maxDotProduct(nums1, nums2), 23);
}

TEST_P(MaxDotProductOfTwoSubsequencesTest, SingleElement) {
  vector<int> nums1 = {5};
  vector<int> nums2 = {7};
  EXPECT_EQ(solution.maxDotProduct(nums1, nums2), 35);
}

TEST_P(MaxDotProductOfTwoSubsequencesTest, OneEmpty) {
  vector<int> nums1 = {1, 2, 3};
  vector<int> nums2 = {};
  // 由于 nums2 为空，无法形成非空子序列，但题目保证两个数组都非空（约束条件：1 <= nums1.length, nums2.length）
  // 所以这个测试用例可以不考虑，但为了完整性，我们可以测试边界情况
  // 根据约束，数组长度至少为1，所以这个测试用例不会出现
}

TEST_P(MaxDotProductOfTwoSubsequencesTest, LargeNumbers) {
  vector<int> nums1(500, 1000);
  vector<int> nums2(500, 1000);
  // 最大点积：500 * 1000 * 1000 = 500,000,000
  EXPECT_EQ(solution.maxDotProduct(nums1, nums2), 500000000);
}

TEST_P(MaxDotProductOfTwoSubsequencesTest, SkipElements) {
  vector<int> nums1 = {1, 100, 1};
  vector<int> nums2 = {1, 1, 100};
  // 最佳配对：1*1 + 100*100 = 1+10000=10001
  EXPECT_EQ(solution.maxDotProduct(nums1, nums2), 10001);
}

TEST_P(MaxDotProductOfTwoSubsequencesTest, NegativeWithZero) {
  vector<int> nums1 = {-5, -1};
  vector<int> nums2 = {0, 0};
  // 最大点积：-1*0 = 0 或 -5*0 = 0，但子序列必须非空，所以至少选一个元素
  // 乘积都是0，所以最大点积是0
  EXPECT_EQ(solution.maxDotProduct(nums1, nums2), 0);
}

TEST_P(MaxDotProductOfTwoSubsequencesTest, AllZeros) {
  vector<int> nums1 = {0, 0, 0};
  vector<int> nums2 = {0, 0};
  // 所有乘积都是0，最大点积是0
  EXPECT_EQ(solution.maxDotProduct(nums1, nums2), 0);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaxDotProductOfTwoSubsequencesTest,
    ::testing::ValuesIn(MaxDotProductOfTwoSubsequencesSolution().getStrategyNames()));

}  // namespace problem_1458
}  // namespace leetcode