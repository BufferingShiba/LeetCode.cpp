#include "leetcode/problems/count-complete-subarrays-in-an-array.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2799 {

class CountCompleteSubarraysInAnArrayTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountCompleteSubarraysInAnArraySolution solution;
};

INSTANTIATE_TEST_SUITE_P(
    LeetCode, CountCompleteSubarraysInAnArrayTest,
    ::testing::ValuesIn(CountCompleteSubarraysInAnArraySolution().getStrategyNames()));

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [1,3,1,2,2]
// Output: 4
TEST_P(CountCompleteSubarraysInAnArrayTest, OfficialExample1) {
  vector<int> nums = {1, 3, 1, 2, 2};
  EXPECT_EQ(4, solution.countCompleteSubarrays(nums));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [5,5,5,5]
// Output: 10
TEST_P(CountCompleteSubarraysInAnArrayTest, OfficialExample2) {
  vector<int> nums = {5, 5, 5, 5};
  EXPECT_EQ(10, solution.countCompleteSubarrays(nums));
}

}  // namespace problem_2799
}  // namespace leetcode
