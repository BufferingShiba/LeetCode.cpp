#include "leetcode/problems/k-diff-pairs-in-an-array.h"

#include <unordered_map>

namespace leetcode::problem_532 {

namespace {

int findPairsImpl(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> count;
    for (int num : nums) {
        ++count[num];
    }

    int result = 0;
    if (k == 0) {
        for (const auto& [num, cnt] : count) {
            if (cnt >= 2) {
                ++result;
            }
        }
        return result;
    }

    for (const auto& [num, cnt] : count) {
        if (count.count(num + k) > 0) {
            ++result;
        }
    }
    return result;
}

}  // namespace

KDiffPairsInAnArraySolution::KDiffPairsInAnArraySolution() {
    setMetaInfo({.id = 532,
                 .title = "K-diff Pairs in an Array",
                 .url = "https://leetcode.com/problems/k-diff-pairs-in-an-array/"});
    registerStrategy({.name = "hashmap-count",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(n)",
                      .tags = {"Array", "Hash Table"}},
                     findPairsImpl);
}

int KDiffPairsInAnArraySolution::findPairs(std::vector<int>& nums, int k) {
    return getSolution()(nums, k);
}

}  // namespace leetcode::problem_532
