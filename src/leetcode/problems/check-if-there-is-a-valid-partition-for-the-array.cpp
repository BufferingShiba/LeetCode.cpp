#include "leetcode/problems/check-if-there-is-a-valid-partition-for-the-array.h"

namespace leetcode::problem_2369 {

static bool validPartitionImpl(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    // dp[i] = 前 i 个元素是否能有效划分
    // 滚动变量: dp0 = dp[i-3], dp1 = dp[i-2], dp2 = dp[i-1]
    bool dp0 = true;   // dp[0] 空数组
    bool dp1 = false;  // dp[1] 只有一个元素，不可能
    bool dp2 = false;  // dp[2]

    if (n >= 2 && nums[0] == nums[1]) {
        dp2 = true;
    }

    for (int i = 3; i <= n; ++i) {
        bool cur = false;
        // 最后一段长度为 2
        if (dp1 && nums[i - 2] == nums[i - 1]) {
            cur = true;
        }
        // 最后一段长度为 3
        if (!cur && dp0) {
            if (nums[i - 3] == nums[i - 2] && nums[i - 2] == nums[i - 1]) {
                cur = true;
            } else if (nums[i - 3] + 1 == nums[i - 2] && nums[i - 2] + 1 == nums[i - 1]) {
                cur = true;
            }
        }
        dp0 = dp1;
        dp1 = dp2;
        dp2 = cur;
    }

    return dp2;
}

CheckIfThereIsAValidPartitionForTheArraySolution::CheckIfThereIsAValidPartitionForTheArraySolution() {
    setMetaInfo({.id = 2369,
                 .title = "Check if There is a Valid Partition For The Array",
                 .url = "https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/"});
    registerStrategy({.name = "DP (O(n) time, O(1) space)",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(1)",
                      .tags = {"Array", "Dynamic Programming"}},
                     validPartitionImpl);
}

bool CheckIfThereIsAValidPartitionForTheArraySolution::validPartition(std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace leetcode::problem_2369
