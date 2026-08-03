#include "leetcode/problems/smallest-index-with-equal-value.h"

#include <vector>

namespace leetcode::problem_2057 {

namespace {

int smallestEqualImpl(std::vector<int>& nums) {
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        if (i % 10 == nums[i]) {
            return i;
        }
    }
    return -1;
}

}  // namespace

int SmallestIndexWithEqualValueSolution::smallestEqual(std::vector<int>& nums) {
    return getSolution()(nums);
}

SmallestIndexWithEqualValueSolution::SmallestIndexWithEqualValueSolution() {
    this->setMetaInfo({.id = 2057, .title = "Smallest Index With Equal Value", .url = "https://leetcode.com/problems/smallest-index-with-equal-value/"});
    this->registerStrategy({.name = "LinearScan", .expected = "Accepted", .time_complexity = "O(n)", .space_complexity = "O(1)", .tags = {"Array"}}, smallestEqualImpl);
}

}  // namespace leetcode::problem_2057
