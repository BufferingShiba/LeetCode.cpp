#include "leetcode/problems/apply-operations-to-an-array.h"

namespace leetcode::problem_2460 {

namespace {

std::vector<int> applyOperationsImpl(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());

    // Step 1: apply the merge operations sequentially.
    for (int i = 0; i + 1 < n; ++i) {
        if (nums[i] == nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }

    // Step 2: shift all zeros to the end.
    std::vector<int> result(n, 0);
    int write = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] != 0) {
            result[write++] = nums[i];
        }
    }
    return result;
}

}  // namespace

ApplyOperationsToAnArraySolution::ApplyOperationsToAnArraySolution() {
    setMetaInfo({.id = 2460,
                 .title = "Apply Operations to an Array",
                 .url = "https://leetcode.com/problems/apply-operations-to-an-array/"});

    registerStrategy({.name = "simulate_shift",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(1)",
                      .tags = {"Array", "Two Pointers", "Simulation"}},
                     applyOperationsImpl);
}

std::vector<int> ApplyOperationsToAnArraySolution::applyOperations(std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace leetcode::problem_2460
