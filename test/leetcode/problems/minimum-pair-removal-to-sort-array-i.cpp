#include "leetcode/problems/minimum-pair-removal-to-sort-array-i.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3507 {

class MinimumPairRemovalToSortArrayITest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumPairRemovalToSortArrayISolution solution;
};

TEST_P(MinimumPairRemovalToSortArrayITest, Example1) {
  vector<int> nums = {5, 2, 3, 1};
  int expected = 2;
  EXPECT_EQ(expected, solution.minimumPairRemoval(nums));
}

TEST_P(MinimumPairRemovalToSortArrayITest, Example2) {
  vector<int> nums = {1, 2, 2};
  int expected = 0;
  EXPECT_EQ(expected, solution.minimumPairRemoval(nums));
}

TEST_P(MinimumPairRemovalToSortArrayITest, SingleElement) {
  vector<int> nums = {5};
  int expected = 0;
  EXPECT_EQ(expected, solution.minimumPairRemoval(nums));
}

TEST_P(MinimumPairRemovalToSortArrayITest, AlreadySorted) {
  vector<int> nums = {1, 2, 3, 4};
  int expected = 0;
  EXPECT_EQ(expected, solution.minimumPairRemoval(nums));
}

TEST_P(MinimumPairRemovalToSortArrayITest, NegativeNumbers) {
  vector<int> nums = {-1, -2, 3};
  int expected = 1;
  EXPECT_EQ(expected, solution.minimumPairRemoval(nums));
}

TEST_P(MinimumPairRemovalToSortArrayITest, AllNegative) {
  vector<int> nums = {-5, -4, -3};
  int expected = 0;
  EXPECT_EQ(expected, solution.minimumPairRemoval(nums));
}

TEST_P(MinimumPairRemovalToSortArrayITest, NeedMultipleOperations) {
  vector<int> nums = {4, 3, 2, 1};
  int expected = 2;
  EXPECT_EQ(expected, solution.minimumPairRemoval(nums));
}

TEST_P(MinimumPairRemovalToSortArrayITest, DecreasingArray) {
  vector<int> nums = {5, 4, 3, 2, 1};
  int expected = 4;
  EXPECT_EQ(expected, solution.minimumPairRemoval(nums));
}

TEST_P(MinimumPairRemovalToSortArrayITest, MixedNumbers) {
  vector<int> nums = {0, -1, 2, -3, 4};
  int expected = 2;
  EXPECT_EQ(expected, solution.minimumPairRemoval(nums));
}

TEST_P(MinimumPairRemovalToSortArrayITest, AllEqual) {
  vector<int> nums = {2, 2, 2, 2};
  int expected = 0;
  EXPECT_EQ(expected, solution.minimumPairRemoval(nums));
}

TEST_P(MinimumPairRemovalToSortArrayITest, LengthTwoAlreadySorted) {
  vector<int> nums = {1, 2};
  int expected = 0;
  EXPECT_EQ(expected, solution.minimumPairRemoval(nums));
}

TEST_P(MinimumPairRemovalToSortArrayITest, LengthTwoNeedOneOperation) {
  vector<int> nums = {2, 1};
  // 合并(2,1)=3 -> [3] 有序
  int expected = 1;
  EXPECT_EQ(expected, solution.minimumPairRemoval(nums));
}

TEST_P(MinimumPairRemovalToSortArrayITest, LargeNumbers) {
  vector<int> nums = {1000, -1000, 1000, -1000};
  // 最小和相邻对：(1000,-1000)=0 最左边
  // 合并后：[0, 1000, -1000]
  // 最小和相邻对：(1000,-1000)=0 最左边
  // 合并后：[0, 0]
  // 有序
  int expected = 2;
  EXPECT_EQ(expected, solution.minimumPairRemoval(nums));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumPairRemovalToSortArrayITest,
    ::testing::ValuesIn(MinimumPairRemovalToSortArrayISolution().getStrategyNames()));

}  // namespace problem_3507
}  // namespace leetcode