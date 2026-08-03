#include "leetcode/problems/count-alternating-subarrays.h"

namespace leetcode {
namespace problem_3101 {

static long long countAlternatingSubarraysImpl(std::vector<int>& nums) {
    long long ans = 0;
    long long curr = 0;
    int prev = -1;  // sentinel different from 0 and 1
    for (int x : nums) {
        if (x != prev) {
            ++curr;
        } else {
            curr = 1;
        }
        ans += curr;
        prev = x;
    }
    return ans;
}

CountAlternatingSubarraysSolution::CountAlternatingSubarraysSolution() {
    setMetaInfo({.id = 3101, .title = "Count Alternating Subarrays", .url = "https://leetcode.com/problems/count-alternating-subarrays/"});
    registerStrategy({
        .name = "LinearScan",
        .expected = "Accepted",
        .time_complexity = "O(n)",
        .space_complexity = "O(1)",
        .tags = {"Array", "Math"}
    }, countAlternatingSubarraysImpl);
}

long long CountAlternatingSubarraysSolution::countAlternatingSubarrays(std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace problem_3101
}  // namespace leetcode
