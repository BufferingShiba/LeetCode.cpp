#include "leetcode/problems/house-robber-ii.h"
#include <algorithm>

namespace leetcode::problem_213 {

static int robLinear(const std::vector<int>& nums, int start, int end) {
    int prev2 = 0;
    int prev1 = 0;
    for (int i = start; i <= end; ++i) {
        int curr = std::max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

static int robImpl(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    if (n == 1) return nums[0];
    return std::max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
}

HouseRobberIiSolution::HouseRobberIiSolution() {
    setMetaInfo({.id = 213, .title = "House Robber II", .url = "https://leetcode.com/problems/house-robber-ii/"});
    registerStrategy({
        .name = "dp-two-pass",
        .expected = "Accepted",
        .time_complexity = "O(n)",
        .space_complexity = "O(1)",
        .tags = {"Array", "Dynamic Programming"}
    }, robImpl);
}

int HouseRobberIiSolution::rob(std::vector<int>& nums) {
    return getSolution()(nums);
}

} // namespace leetcode::problem_213
