#include "leetcode/problems/maximum-alternating-subsequence-sum.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_1911 {

static long long maxAlternatingSumImpl(std::vector<int>& nums) {
    long long even = nums[0];  // subsequence ends at even index (next is subtract)
    long long odd = 0;         // subsequence ends at odd index (next is add)

    for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
        long long new_even = std::max({even, odd + nums[i], static_cast<long long>(nums[i])});
        long long new_odd = std::max(odd, even - nums[i]);
        even = new_even;
        odd = new_odd;
    }

    return std::max(even, odd);
}

MaximumAlternatingSubsequenceSumSolution::MaximumAlternatingSubsequenceSumSolution() {
    setMetaInfo({.id = 1911,
                 .title = "Maximum Alternating Subsequence Sum",
                 .url = "https://leetcode.com/problems/maximum-alternating-subsequence-sum/"});
    registerStrategy(
        {.name = "DP",
         .expected = "Accepted",
         .time_complexity = "O(n)",
         .space_complexity = "O(1)",
         .tags = {"Array", "Dynamic Programming"}},
        maxAlternatingSumImpl);
}

long long MaximumAlternatingSubsequenceSumSolution::maxAlternatingSum(std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace problem_1911
}  // namespace leetcode
