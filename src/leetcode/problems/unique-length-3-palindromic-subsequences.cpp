#include "leetcode/problems/unique-length-3-palindromic-subsequences.h"

#include <algorithm>
#include <array>
#include <string>

namespace leetcode {
namespace problem_1930 {

namespace {

int countPalindromicSubsequenceImpl(const std::string& s) {
    const int n = static_cast<int>(s.size());
    std::array<int, 26> first;
    std::array<int, 26> last;
    first.fill(-1);
    last.fill(-1);
    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a';
        if (first[c] == -1) first[c] = i;
        last[c] = i;
    }
    int ans = 0;
    for (int c = 0; c < 26; ++c) {
        if (first[c] == -1 || first[c] >= last[c]) continue;
        // Count distinct characters strictly between first[c] and last[c].
        bool seen[26] = {false};
        int cnt = 0;
        for (int i = first[c] + 1; i < last[c]; ++i) {
            int ch = s[i] - 'a';
            if (!seen[ch]) {
                seen[ch] = true;
                ++cnt;
            }
        }
        ans += cnt;
    }
    return ans;
}

}  // namespace

UniqueLength3PalindromicSubsequencesSolution::UniqueLength3PalindromicSubsequencesSolution() {
    setMetaInfo({.id = 1930,
                 .title = "Unique Length-3 Palindromic Subsequences",
                 .url = "https://leetcode.com/problems/unique-length-3-palindromic-subsequences/"});
    registerStrategy({.name = "FirstLastWindow",
                      .expected = "Accepted",
                      .time_complexity = "O(26 * n)",
                      .space_complexity = "O(26)",
                      .tags = {"Hash Table", "String", "Bit Manipulation", "Prefix Sum"}},
                     countPalindromicSubsequenceImpl);
}

int UniqueLength3PalindromicSubsequencesSolution::countPalindromicSubsequence(std::string s) {
    return getSolution()(std::move(s));
}

}  // namespace problem_1930
}  // namespace leetcode
