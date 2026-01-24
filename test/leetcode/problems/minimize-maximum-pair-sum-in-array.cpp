
#include "leetcode/problems/minimize-maximum-pair-sum-in-array.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1877 {

class MinimizeMaximumPairSumInArrayTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimizeMaximumPairSumInArraySolution solution;
};

TEST_P(MinimizeMaximumPairSumInArrayTest, Example1) {
  vector<int> nums = {3, 5, 2, 3};
  int expected = 7;
  EXPECT_EQ(expected, solution.minPairSum(nums));
}

TEST_P(MinimizeMaximumPairSumInArrayTest, Example2) {
  vector<int> nums = {3, 5, 4, 2, 4, 6};
  int expected = 8;
  EXPECT_EQ(expected, solution.minPairSum(nums));
}

TEST_P(MinimizeMaximumPairSumInArrayTest, AllEqual) {
  vector<int> nums = {1, 1, 1, 1};
  int expected = 2;
  EXPECT_EQ(expected, solution.minPairSum(nums));
}

TEST_P(MinimizeMaximumPairSumInArrayTest, IncreasingSequence) {
  vector<int> nums = {1, 2, 3, 4};
  int expected = 5;  // 1+4=5, 2+3=5
  EXPECT_EQ(expected, solution.minPairSum(nums));
}

TEST_P(MinimizeMaximumPairSumInArrayTest, LargeRange) {
  vector<int> nums = {1, 100, 2, 99, 3, 98};
  int expected = 101;  // 1+100=101, 2+99=101, 3+98=101
  EXPECT_EQ(expected, solution.minPairSum(nums));
}

TEST_P(MinimizeMaximumPairSumInArrayTest, TwoElements) {
  vector<int> nums = {1, 2};
  int expected = 3;
  EXPECT_EQ(expected, solution.minPairSum(nums));
}

TEST_P(MinimizeMaximumPairSumInArrayTest, RandomCase1) {
  vector<int> nums = {4, 1, 5, 8, 2, 7, 3, 6};
  // Sorted: [1,2,3,4,5,6,7,8]
  // Pairs: (1,8)=9, (2,7)=9, (3,6)=9, (4,5)=9
  int expected = 9;
  EXPECT_EQ(expected, solution.minPairSum(nums));
}

TEST_P(MinimizeMaximumPairSumInArrayTest, RandomCase2) {
  vector<int> nums = {10, 5, 20, 15, 30, 25};
  // Sorted: [5,10,15,20,25,30]
  // Pairs: (5,30)=35, (10,25)=35, (15,20)=35
  int expected = 35;
  EXPECT_EQ(expected, solution.minPairSum(nums));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimizeMaximumPairSumInArrayTest,
    ::testing::ValuesIn(MinimizeMaximumPairSumInArraySolution().getStrategyNames()));

}  // namespace problem_1877
}  // namespace leetcode