#include "leetcode/problems/stable-subarrays-with-equal-boundary-and-interior-sum.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3728 {

class StableSubarraysWithEqualBoundaryAndInteriorSumTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  StableSubarraysWithEqualBoundaryAndInteriorSumSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  capacity = [9,3,3,3,9]
// Output: 2
TEST_P(StableSubarraysWithEqualBoundaryAndInteriorSumTest, OfficialExample1) {
  vector<int> capacity = {9, 3, 3, 3, 9};
  EXPECT_EQ(2LL, solution.countStableSubarrays(capacity));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  capacity = [1,2,3,4,5]
// Output: 0
TEST_P(StableSubarraysWithEqualBoundaryAndInteriorSumTest, OfficialExample2) {
  vector<int> capacity = {1, 2, 3, 4, 5};
  EXPECT_EQ(0LL, solution.countStableSubarrays(capacity));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  capacity = [-4,4,0,0,-8,-4]
// Output: 1
TEST_P(StableSubarraysWithEqualBoundaryAndInteriorSumTest, OfficialExample3) {
  vector<int> capacity = {-4, 4, 0, 0, -8, -4};
  EXPECT_EQ(1LL, solution.countStableSubarrays(capacity));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, StableSubarraysWithEqualBoundaryAndInteriorSumTest,
    ::testing::ValuesIn(StableSubarraysWithEqualBoundaryAndInteriorSumSolution().getStrategyNames()));

}  // namespace problem_3728
}  // namespace leetcode
