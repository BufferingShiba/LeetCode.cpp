#include "leetcode/problems/maximize-total-cost-of-alternating-subarrays.h"

#include <algorithm>
#include <climits>

namespace leetcode {
namespace problem_3196 {

static long long maximumTotalCostImpl(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    long long f = nums[0];          // dp[i][0]: nums[i] ends with positive sign
    long long g = LLONG_MIN / 2;    // dp[i][1]: nums[i] ends with negative sign (invalid for i=0)

    for (int i = 1; i < n; ++i) {
        long long new_f = nums[i] + std::max(f, g);
        long long new_g = -static_cast<long long>(nums[i]) + f;
        f = new_f;
        g = new_g;
    }

    return std::max(f, g);
}

MaximizeTotalCostOfAlternatingSubarraysSolution::MaximizeTotalCostOfAlternatingSubarraysSolution() {
    setMetaInfo({.id = 3196,
                 .title = "Maximize Total Cost of Alternating Subarrays",
                 .url = "https://leetcode.com/problems/maximize-total-cost-of-alternating-subarrays/"});
    registerStrategy({.name = "DP",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(1)",
                      .tags = {"Array", "Dynamic Programming"}},
                     maximumTotalCostImpl);
}

long long MaximizeTotalCostOfAlternatingSubarraysSolution::maximumTotalCost(std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace problem_3196
}  // namespace leetcode
