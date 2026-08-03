#include "leetcode/problems/equal-score-substrings.h"

namespace leetcode::problem_3707 {

namespace {

bool scoreBalanceImpl(const std::string& s) {
    int total = 0;
    for (char c : s) {
        total += (c - 'a' + 1);
    }
    int left = 0;
    // Split must leave both substrings non-empty, so i goes 0..n-2.
    for (int i = 0; i + 1 < static_cast<int>(s.size()); ++i) {
        left += (s[i] - 'a' + 1);
        if (2 * left == total) {
            return true;
        }
    }
    return false;
}

}  // namespace

EqualScoreSubstringsSolution::EqualScoreSubstringsSolution() {
    setMetaInfo({.id = 3707,
                 .title = "Equal Score Substrings",
                 .url = "https://leetcode.com/problems/equal-score-substrings/"});
    registerStrategy(
        {.name = "PrefixSum",
         .expected = "Accepted",
         .time_complexity = "O(n)",
         .space_complexity = "O(1)",
         .tags = {"String", "Prefix Sum"}},
        scoreBalanceImpl);
}

bool EqualScoreSubstringsSolution::scoreBalance(std::string s) {
    return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_3707
