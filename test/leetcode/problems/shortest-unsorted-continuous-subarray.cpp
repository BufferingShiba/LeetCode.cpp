#include "leetcode/problems/shortest-unsorted-continuous-subarray.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_581 {

class ShortestUnsortedContinuousSubarrayTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ShortestUnsortedContinuousSubarraySolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [2,6,4,8,10,9,15]
// Output: 5
TEST_P(ShortestUnsortedContinuousSubarrayTest, OfficialExample1) {
  std::vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
  int result = solution.findUnsortedSubarray(nums);
  EXPECT_EQ(5, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [1,2,3,4]
// Output: 0
TEST_P(ShortestUnsortedContinuousSubarrayTest, OfficialExample2) {
  std::vector<int> nums = {1, 2, 3, 4};
  int result = solution.findUnsortedSubarray(nums);
  EXPECT_EQ(0, result);
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  nums = [1]
// Output: 0
TEST_P(ShortestUnsortedContinuousSubarrayTest, OfficialExample3) {
  std::vector<int> nums = {1};
  int result = solution.findUnsortedSubarray(nums);
  EXPECT_EQ(0, result);
}

// ===== More edge cases =====
TEST_P(ShortestUnsortedContinuousSubarrayTest, DescendingArray) {
  std::vector<int> nums = {5, 4, 3, 2, 1};
  int result = solution.findUnsortedSubarray(nums);
  EXPECT_EQ(5, result);
}

TEST_P(ShortestUnsortedContinuousSubarrayTest, UnsortedMiddle) {
  std::vector<int> nums = {1, 3, 2, 4};
  int result = solution.findUnsortedSubarray(nums);
  EXPECT_EQ(2, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, ShortestUnsortedContinuousSubarrayTest,
    ::testing::ValuesIn(ShortestUnsortedContinuousSubarraySolution().getStrategyNames()));

}  // namespace problem_581
}  // namespace leetcode
