#include "leetcode/problems/maximum-erasure-value.h"

#include <unordered_set>

namespace leetcode::problem_1695 {
namespace {

int maximumUniqueSubarrayImpl(std::vector<int>& nums) {
    std::unordered_set<int> seen;
    int left = 0;
    int sum = 0;
    int best = 0;
    for (int right = 0; right < static_cast<int>(nums.size()); ++right) {
        while (seen.count(nums[right])) {
            seen.erase(nums[left]);
            sum -= nums[left];
            ++left;
        }
        seen.insert(nums[right]);
        sum += nums[right];
        if (sum > best) best = sum;
    }
    return best;
}

}  // namespace

int MaximumErasureValueSolution::maximumUniqueSubarray(std::vector<int>& nums) {
    return getSolution()(nums);
}

MaximumErasureValueSolution::MaximumErasureValueSolution() {
    setMetaInfo({.id = 1695,
                 .title = "Maximum Erasure Value",
                 .url =
                     "https://leetcode.com/problems/maximum-erasure-value/"});
    registerStrategy({.name = "SlidingWindow",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(n)",
                      .tags = {"Array", "Hash Table", "Sliding Window"}},
                     maximumUniqueSubarrayImpl);
}

}  // namespace leetcode::problem_1695
