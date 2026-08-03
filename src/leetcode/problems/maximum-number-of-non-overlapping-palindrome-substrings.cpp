#include "leetcode/problems/maximum-number-of-non-overlapping-palindrome-substrings.h"

namespace leetcode {
namespace problem_2472 {

namespace {

int maxPalindromesImpl(const std::string& s, int k) {
    const int n = static_cast<int>(s.size());
    std::vector<std::vector<bool>> pal(n, std::vector<bool>(n, false));
    for (int len = 1; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            const int r = l + len - 1;
            if (s[l] == s[r] && (len <= 2 || pal[l + 1][r - 1])) {
                pal[l][r] = true;
            }
        }
    }

    const int INF = n;
    std::vector<int> minEnd(n, INF);
    for (int i = 0; i < n; ++i) {
        for (int r = std::max(i, i + k - 1); r < n; ++r) {
            if (pal[i][r]) {
                minEnd[i] = r;
                break;
            }
        }
    }

    std::vector<int> f(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        f[i] = f[i + 1];
        if (minEnd[i] != INF) {
            f[i] = std::max(f[i], 1 + f[minEnd[i] + 1]);
        }
    }
    return f[0];
}

}  // namespace

MaximumNumberOfNonOverlappingPalindromeSubstringsSolution::MaximumNumberOfNonOverlappingPalindromeSubstringsSolution() {
    setMetaInfo({.id = 2472,
                 .title = "Maximum Number of Non-overlapping Palindrome Substrings",
                 .url = "https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/"});
    registerStrategy({.name = "PalTableSuffixDP",
                      .expected = "Accepted",
                      .time_complexity = "O(n^2)",
                      .space_complexity = "O(n^2)",
                      .tags = {"String", "Dynamic Programming", "Greedy", "Two Pointers"}},
                     [](std::string s, int k) { return maxPalindromesImpl(s, k); });
}

int MaximumNumberOfNonOverlappingPalindromeSubstringsSolution::maxPalindromes(std::string s, int k) {
    return getSolution()(std::move(s), k);
}

}  // namespace problem_2472
}  // namespace leetcode
