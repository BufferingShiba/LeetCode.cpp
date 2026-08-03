#include "leetcode/problems/minimum-deletions-to-make-array-beautiful.h"

namespace leetcode {
namespace problem_2216 {

namespace {

int minDeletionImpl(std::vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        if (res % 2 == 0) {
            // Even-index position: place current element.
            ++res;
        } else if (res > 0 && nums[i] != nums[i - 1]) {
            // Odd-index: accept only if different from previous kept element.
            ++res;
        }
    }
    // Final length must be even.
    return static_cast<int>(nums.size()) - res + (res % 2);
}

}  // namespace

MinimumDeletionsToMakeArrayBeautifulSolution::
    MinimumDeletionsToMakeArrayBeautifulSolution() {
    setMetaInfo({.id = 2216,
                 .title = "Minimum Deletions to Make Array Beautiful",
                 .url = "https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/"});

    registerStrategy(
        {.name = "greedy",
         .expected = "Accepted",
         .time_complexity = "O(n)",
         .space_complexity = "O(1)",
         .tags = {"Array", "Greedy"}},
        minDeletionImpl);
}

int MinimumDeletionsToMakeArrayBeautifulSolution::minDeletion(
    std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace problem_2216
}  // namespace leetcode
