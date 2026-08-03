#include "leetcode/problems/sort-array-by-increasing-frequency.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1636 {

class SortArrayByIncreasingFrequencyTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SortArrayByIncreasingFrequencySolution solution;
};

INSTANTIATE_TEST_SUITE_P(
    LeetCode, SortArrayByIncreasingFrequencyTest,
    ::testing::ValuesIn(SortArrayByIncreasingFrequencySolution().getStrategyNames()));

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
TEST_P(SortArrayByIncreasingFrequencyTest, OfficialExample1) {
  vector<int> nums{1,1,2,2,2,3};
  vector<int> expected{3,1,1,2,2,2};
  EXPECT_EQ(expected, solution.frequencySort(nums));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [2,3,1,3,2]
// Output: [1,3,3,2,2]
TEST_P(SortArrayByIncreasingFrequencyTest, OfficialExample2) {
  vector<int> nums{2,3,1,3,2};
  vector<int> expected{1,3,3,2,2};
  EXPECT_EQ(expected, solution.frequencySort(nums));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  nums = [-1,1,-6,4,5,-6,1,4,1]
// Output: [5,-1,4,4,-6,-6,1,1,1]
TEST_P(SortArrayByIncreasingFrequencyTest, OfficialExample3) {
  vector<int> nums{-1,1,-6,4,5,-6,1,4,1};
  vector<int> expected{5,-1,4,4,-6,-6,1,1,1};
  EXPECT_EQ(expected, solution.frequencySort(nums));
}

}  // namespace problem_1636
}  // namespace leetcode
