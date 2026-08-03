#include "leetcode/problems/minimum-number-of-removals-to-make-mountain-array.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_1671 {

// Strategy 1: DP O(n²) — bidirectional LIS
static int minimumMountainRemovalsDP(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    std::vector<int> lis(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                lis[i] = std::max(lis[i], lis[j] + 1);
            }
        }
    }

    std::vector<int> lds(n, 1);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (nums[j] < nums[i]) {
                lds[i] = std::max(lds[i], lds[j] + 1);
            }
        }
    }

    int max_mountain = 0;
    for (int i = 0; i < n; ++i) {
        if (lis[i] >= 2 && lds[i] >= 2) {
            max_mountain = std::max(max_mountain, lis[i] + lds[i] - 1);
        }
    }

    return n - max_mountain;
}

// Strategy 2: Binary Search + Patience Sorting O(n log n)
static int minimumMountainRemovalsBS(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    std::vector<int> lis(n, 1);
    std::vector<int> lds(n, 1);
    std::vector<int> tails;

    // LIS ending at i
    for (int i = 0; i < n; ++i) {
        auto it = std::lower_bound(tails.begin(), tails.end(), nums[i]);
        if (it == tails.end()) {
            tails.push_back(nums[i]);
            lis[i] = static_cast<int>(tails.size());
        } else {
            *it = nums[i];
            lis[i] = static_cast<int>(it - tails.begin() + 1);
        }
    }

    tails.clear();
    // LDS starting at i (equivalent to LIS from the right)
    for (int i = n - 1; i >= 0; --i) {
        auto it = std::lower_bound(tails.begin(), tails.end(), nums[i]);
        if (it == tails.end()) {
            tails.push_back(nums[i]);
            lds[i] = static_cast<int>(tails.size());
        } else {
            *it = nums[i];
            lds[i] = static_cast<int>(it - tails.begin() + 1);
        }
    }

    int max_mountain = 0;
    for (int i = 0; i < n; ++i) {
        if (lis[i] >= 2 && lds[i] >= 2) {
            max_mountain = std::max(max_mountain, lis[i] + lds[i] - 1);
        }
    }

    return n - max_mountain;
}

MinimumNumberOfRemovalsToMakeMountainArraySolution::
    MinimumNumberOfRemovalsToMakeMountainArraySolution() {
    setMetaInfo({.id = 1671,
                 .title = "Minimum Number of Removals to Make Mountain Array",
                 .url = "https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/"});

    registerStrategy({.name = "DP O(n^2)",
                      .expected = "Accepted",
                      .time_complexity = "O(n^2)",
                      .space_complexity = "O(n)",
                      .tags = {"Array", "Dynamic Programming"}},
                     minimumMountainRemovalsDP);

    registerStrategy({.name = "Binary Search O(n log n)",
                      .expected = "Accepted",
                      .time_complexity = "O(n log n)",
                      .space_complexity = "O(n)",
                      .tags = {"Array", "Binary Search", "Dynamic Programming", "Greedy"}},
                     minimumMountainRemovalsBS);
}

int MinimumNumberOfRemovalsToMakeMountainArraySolution::minimumMountainRemovals(
    std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace problem_1671
}  // namespace leetcode
