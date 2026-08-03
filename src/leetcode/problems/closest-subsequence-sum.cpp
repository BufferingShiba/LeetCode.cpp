#include "leetcode/problems/closest-subsequence-sum.h"

#include <algorithm>
#include <cstdlib>

namespace leetcode {
namespace problem_1755 {

namespace {

// Enumerate all subset sums of nums[begin, end) using DP-style incremental generation.
std::vector<long long> allSubsetSums(const std::vector<int>& nums, int begin, int end) {
    std::vector<long long> sums;
    sums.reserve(1 << (end - begin));
    sums.push_back(0);
    for (int i = begin; i < end; ++i) {
        int cur = static_cast<int>(sums.size());
        for (int j = 0; j < cur; ++j) {
            sums.push_back(sums[j] + nums[i]);
        }
    }
    return sums;
}

}  // namespace

int ClosestSubsequenceSumSolution::solveClosestSubsequenceSum(std::vector<int>& nums, int goal) {
    int n = static_cast<int>(nums.size());
    int mid = n / 2;

    // Generate all subset sums for each half.
    std::vector<long long> left = allSubsetSums(nums, 0, mid);
    std::vector<long long> right = allSubsetSums(nums, mid, n);

    std::sort(right.begin(), right.end());

    long long g = goal;
    long long best = llabs(g);  // empty subsequence: sum=0 -> |0-goal|

    for (long long ls : left) {
        long long target = g - ls;
        // Find the closest right sum to target using binary search.
        auto it = std::lower_bound(right.begin(), right.end(), target);
        if (it != right.end()) {
            best = std::min(best, llabs(ls + (*it) - g));
        }
        if (it != right.begin()) {
            --it;
            best = std::min(best, llabs(ls + (*it) - g));
        }
    }

    return static_cast<int>(best);
}

}  // namespace problem_1755
}  // namespace leetcode
