#include "leetcode/problems/minimum-operations-to-reach-target-array.h"
#include <unordered_set>

namespace leetcode {
namespace problem_3810 {

static int minOperationsImpl(std::vector<int>& nums, std::vector<int>& target) {
    std::unordered_set<int> need_change;
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        if (nums[i] != target[i]) {
            need_change.insert(nums[i]);
        }
    }
    return static_cast<int>(need_change.size());
}

MinimumOperationsToReachTargetArraySolution::MinimumOperationsToReachTargetArraySolution() {
    setMetaInfo({.id = 3810, .title = "Minimum Operations to Reach Target Array", .url = "https://leetcode.com/problems/minimum-operations-to-reach-target-array/"});
    registerStrategy({.name = "HashSet", .expected = "Accepted", .time_complexity = "O(n)", .space_complexity = "O(k)", .tags = {"Array", "Hash Table", "Greedy"}}, minOperationsImpl);
}

int MinimumOperationsToReachTargetArraySolution::minOperations(std::vector<int>& nums, std::vector<int>& target) {
    return getSolution()(nums, target);
}

}  // namespace problem_3810
}  // namespace leetcode
