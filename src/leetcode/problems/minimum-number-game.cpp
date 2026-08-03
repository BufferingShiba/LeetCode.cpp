#include "leetcode/problems/minimum-number-game.h"

#include <algorithm>

namespace leetcode::problem_2974 {

namespace {

std::vector<int> numberGameImpl(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    for (std::size_t i = 0; i + 1 < nums.size(); i += 2) {
        std::swap(nums[i], nums[i + 1]);
    }
    return nums;
}

}  // namespace

MinimumNumberGameSolution::MinimumNumberGameSolution() {
    setMetaInfo({.id = 2974,
                 .title = "Minimum Number Game",
                 .url = "https://leetcode.com/problems/minimum-number-game/"});
    registerStrategy({.name = "SortAndSwapPairs",
                      .expected = "Accepted",
                      .time_complexity = "O(n log n)",
                      .space_complexity = "O(log n)",
                      .tags = {"Array", "Sorting"},
                      .notes = "Sort then swap adjacent pairs"},
                     numberGameImpl);
}

std::vector<int> MinimumNumberGameSolution::numberGame(std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace leetcode::problem_2974
