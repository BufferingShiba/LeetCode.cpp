#include "leetcode/problems/shuffle-the-array.h"

namespace leetcode::problem_1470 {

namespace {

std::vector<int> shuffleImpl(std::vector<int>& nums, int n) {
    std::vector<int> result;
    result.reserve(2 * n);
    for (int i = 0; i < n; ++i) {
        result.push_back(nums[i]);
        result.push_back(nums[n + i]);
    }
    return result;
}

}  // namespace

ShuffleTheArraySolution::ShuffleTheArraySolution() {
    setMetaInfo({.id = 1470,
                 .title = "Shuffle the Array",
                 .url = "https://leetcode.com/problems/shuffle-the-array/"});
    registerStrategy({.name = "Interleave",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(n)",
                      .tags = {"Array"}},
                     shuffleImpl);
}

std::vector<int> ShuffleTheArraySolution::shuffle(std::vector<int>& nums, int n) {
    return getSolution()(nums, n);
}

}  // namespace leetcode::problem_1470
