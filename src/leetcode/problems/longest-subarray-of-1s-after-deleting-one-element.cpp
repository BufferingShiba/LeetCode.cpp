#include "leetcode/problems/longest-subarray-of-1s-after-deleting-one-element.h"

namespace {

int slidingWindow(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    int left = 0;
    int count0 = 0;
    int ans = 0;
    for (int right = 0; right < n; ++right) {
        if (nums[right] == 0) {
            ++count0;
        }
        while (count0 > 1) {
            if (nums[left] == 0) {
                --count0;
            }
            ++left;
        }
        // window [left, right] contains at most one 0.
        // Deleting that 0 leaves (right - left) consecutive 1's.
        ans = std::max(ans, right - left);
    }
    return ans;
}

}  // namespace

namespace leetcode {
namespace problem_1493 {

LongestSubarrayOf1sAfterDeletingOneElementSolution::LongestSubarrayOf1sAfterDeletingOneElementSolution() {
    setMetaInfo({.id = 1493,
                 .title = "Longest Subarray of 1's After Deleting One Element",
                 .url = "https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/"});
    registerStrategy({.name = "SlidingWindow",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(1)",
                      .tags = {"Array", "Sliding Window"}},
                     slidingWindow);
}

int LongestSubarrayOf1sAfterDeletingOneElementSolution::longestSubarray(std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace problem_1493
}  // namespace leetcode
