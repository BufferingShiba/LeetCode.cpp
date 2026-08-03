#include "leetcode/problems/longest-subarray-with-maximum-bitwise-and.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_2419 {

namespace {

// The maximum bitwise AND over all subarrays equals max(nums), because a
// single-element subarray [nums[i]] already achieves AND == nums[i].
// Any multi-element subarray has AND <= its minimum element <= max(nums).
// A subarray's AND equals max(nums) iff every element in it equals max(nums).
// So the answer is the length of the longest contiguous run of max(nums).
int longestSubarrayMaxRun(std::vector<int>& nums) {
    const int max_val = *std::max_element(nums.begin(), nums.end());
    int best = 0;
    int cur = 0;
    for (int v : nums) {
        if (v == max_val) {
            ++cur;
            best = std::max(best, cur);
        } else {
            cur = 0;
        }
    }
    return best;
}

}  // namespace

LongestSubarrayWithMaximumBitwiseAndSolution::
    LongestSubarrayWithMaximumBitwiseAndSolution() {
    this->setMetaInfo({.
        id = 2419,
        .title = "Longest Subarray With Maximum Bitwise AND",
        .url =
            "https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/"
    });

    this->registerStrategy(
        {.name = "MaximumRunOfMaxValue",
         .expected = "Accepted",
         .time_complexity = "O(n)",
         .space_complexity = "O(1)",
         .tags = {"Array", "Bit Manipulation"},
         .notes =
             "k = max(nums); longest contiguous run equal to k."},
        longestSubarrayMaxRun);
}

int LongestSubarrayWithMaximumBitwiseAndSolution::longestSubarray(
    std::vector<int>& nums) {
    return this->getSolution()(nums);
}

}  // namespace problem_2419
}  // namespace leetcode
