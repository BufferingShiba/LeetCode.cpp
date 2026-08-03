#include "leetcode/problems/maximum-median-sum-of-subsequences-of-size-3.h"

#include <algorithm>

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3627 {

class MaximumMedianSumOfSubsequencesOfSize3Test : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumMedianSumOfSubsequencesOfSize3Solution solution;
};

static long long bruteMaximumMedianSum(const std::vector<int>& nums,
                                       std::vector<bool>& used) {
  int first = -1;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (!used[i]) {
      first = i;
      break;
    }
  }
  if (first == -1) return 0;

  long long best = -1;
  used[first] = true;
  for (int second = first + 1; second < static_cast<int>(nums.size()); ++second) {
    if (used[second]) continue;
    used[second] = true;
    for (int third = second + 1; third < static_cast<int>(nums.size()); ++third) {
      if (used[third]) continue;
      used[third] = true;
      const int median = nums[first] + nums[second] + nums[third] -
                         std::min({nums[first], nums[second], nums[third]}) -
                         std::max({nums[first], nums[second], nums[third]});
      best = std::max(best, median + bruteMaximumMedianSum(nums, used));
      used[third] = false;
    }
    used[second] = false;
  }
  used[first] = false;
  return best;
}

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [2,1,3,2,1,3]
// Output: 5
TEST_P(MaximumMedianSumOfSubsequencesOfSize3Test, OfficialExample1) {
  std::vector<int> nums = {2, 1, 3, 2, 1, 3};
  EXPECT_EQ(5, solution.maximumMedianSum(nums));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [1,1,10,10,10,10]
// Output: 20
TEST_P(MaximumMedianSumOfSubsequencesOfSize3Test, OfficialExample2) {
  std::vector<int> nums = {1, 1, 10, 10, 10, 10};
  EXPECT_EQ(20, solution.maximumMedianSum(nums));
}

// ===== SelfAuthored: all equal elements =====
// Only one way to partition; every median equals that value.
TEST_P(MaximumMedianSumOfSubsequencesOfSize3Test, AllEqual) {
  std::vector<int> nums = {7, 7, 7, 7, 7, 7, 7, 7, 7};
  EXPECT_EQ(21, solution.maximumMedianSum(nums));
}

// ===== SelfAuthored: single triple =====
TEST_P(MaximumMedianSumOfSubsequencesOfSize3Test, SingleTriple) {
  std::vector<int> nums = {3, 1, 2};
  EXPECT_EQ(2, solution.maximumMedianSum(nums));
}

TEST_P(MaximumMedianSumOfSubsequencesOfSize3Test, ExhaustiveSmallInputs) {
  // For values in {1,2,3}, compare the greedy against every partition for
  // n=3, 6, and 9.  This exercises the placement of both the largest and the
  // smallest unused values in the triples.
  for (int n = 3; n <= 9; n += 3) {
    std::vector<int> nums(n);
    std::function<void(int)> enumerate = [&](int index) {
      if (index == n) {
        std::vector<bool> used(n, false);
        std::vector<int> input = nums;
        EXPECT_EQ(bruteMaximumMedianSum(nums, used),
                  solution.maximumMedianSum(input));
        return;
      }
      for (int value = 1; value <= 3; ++value) {
        nums[index] = value;
        enumerate(index + 1);
      }
    };
    enumerate(0);
  }
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaximumMedianSumOfSubsequencesOfSize3Test,
    ::testing::ValuesIn(MaximumMedianSumOfSubsequencesOfSize3Solution().getStrategyNames()));

}  // namespace problem_3627
}  // namespace leetcode
