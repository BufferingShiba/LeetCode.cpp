#include "leetcode/problems/longest-mountain-in-array.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_845 {

class LongestMountainInArrayTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongestMountainInArraySolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  arr = [2,1,4,7,3,2,5]
// Output: 5
TEST_P(LongestMountainInArrayTest, OfficialExample1) {
  std::vector<int> arr = {2,1,4,7,3,2,5};
  EXPECT_EQ(5, solution.longestMountain(arr));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  arr = [2,2,2]
// Output: 0
TEST_P(LongestMountainInArrayTest, OfficialExample2) {
  std::vector<int> arr = {2,2,2};
  EXPECT_EQ(0, solution.longestMountain(arr));
}

// ===== Regression: a descending run has no rising slope =====
TEST_P(LongestMountainInArrayTest, StrictlyDecreasing) {
  std::vector<int> arr = {9,8,7,6,5,4,3,2,1,0};
  EXPECT_EQ(0, solution.longestMountain(arr));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, LongestMountainInArrayTest,
    ::testing::ValuesIn(LongestMountainInArraySolution().getStrategyNames()));

}  // namespace problem_845
}  // namespace leetcode
