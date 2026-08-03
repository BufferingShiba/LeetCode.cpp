#include "leetcode/problems/squares-of-a-sorted-array.h"

#include <vector>

namespace leetcode::problem_977 {

namespace {

std::vector<int> sortedSquaresImpl(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    std::vector<int> result(n);
    int left = 0;
    int right = n - 1;
    for (int pos = n - 1; pos >= 0; --pos) {
        const int lsq = nums[left] * nums[left];
        const int rsq = nums[right] * nums[right];
        if (lsq > rsq) {
            result[pos] = lsq;
            ++left;
        } else {
            result[pos] = rsq;
            --right;
        }
    }
    return result;
}

}  // namespace

std::vector<int> SquaresOfASortedArraySolution::sortedSquares(
    std::vector<int>& nums) {
    return getSolution()(nums);
}

SquaresOfASortedArraySolution::SquaresOfASortedArraySolution() {
    setMetaInfo({.id = 977,
                 .title = "Squares of a Sorted Array",
                 .url =
                     "https://leetcode.com/problems/squares-of-a-sorted-array/"});
    registerStrategy(
        {.name = "TwoPointers",
         .expected = "Accepted",
         .time_complexity = "O(n)",
         .space_complexity = "O(1)",
         .tags = {"Array", "Two Pointers", "Sorting"}},
        sortedSquaresImpl);
}

}  // namespace leetcode::problem_977
