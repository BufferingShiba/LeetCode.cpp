#include "leetcode/problems/find-subarray-with-bitwise-or-closest-to-k.h"

#include <algorithm>
#include <cstdlib>
#include <unordered_set>
#include <vector>

namespace leetcode::problem_3171 {

static int minimumDifferenceImpl(std::vector<int>& nums, int k) {
    int ans = std::abs(k - nums[0]);
    std::unordered_set<int> prev;
    for (int x : nums) {
        std::unordered_set<int> cur;
        cur.insert(x);
        for (int v : prev) {
            cur.insert(v | x);
        }
        for (int v : cur) {
            ans = std::min(ans, std::abs(k - v));
        }
        if (ans == 0) return 0;
        prev = std::move(cur);
    }
    return ans;
}

FindSubarrayWithBitwiseOrClosestToKSolution::FindSubarrayWithBitwiseOrClosestToKSolution() {
    setMetaInfo({.id = 3171,
                 .title = "Find Subarray With Bitwise OR Closest to K",
                 .url = "https://leetcode.com/problems/find-subarray-with-bitwise-or-closest-to-k/"});
    registerStrategy({.name = "iterative_set",
                      .expected = "Accepted",
                      .time_complexity = "O(n * log U)",
                      .space_complexity = "O(log U)",
                      .tags = {"Array", "Bit Manipulation"}},
                     minimumDifferenceImpl);
    setDefaultStrategy();
}

int FindSubarrayWithBitwiseOrClosestToKSolution::minimumDifference(std::vector<int>& nums, int k) {
    return getSolution()(nums, k);
}

}  // namespace leetcode::problem_3171
