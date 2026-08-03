#include "leetcode/problems/find-all-good-strings.h"

#include <vector>

namespace leetcode {
namespace problem_1397 {
namespace {

const long long MOD = 1000000007LL;

// KMP prefix function.
std::vector<int> buildKmp(const std::string& evil) {
    int m = evil.size();
    std::vector<int> pi(m, 0);
    for (int i = 1; i < m; ++i) {
        int j = pi[i - 1];
        while (j > 0 && evil[i] != evil[j]) j = pi[j - 1];
        if (evil[i] == evil[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

// Count strings of length n, lexicographically <= bound, not containing evil,
// and whose current match length (KMP auto state) is `startMatch` before
// processing `bound`.
long long countLe(const std::string& bound, const std::string& evil,
                  const std::vector<int>& pi, int startMatch) {
    int n = bound.size();
    int m = evil.size();
    // dp[pos][match][tight]
    // match in [0, m-1] (m states, state m is forbidden).
    // dims: (n+1) x m x 2
    std::vector<std::vector<std::vector<long long>>> dp(
        n + 1, std::vector<std::vector<long long>>(
                   m, std::vector<long long>(2, 0)));
    dp[0][startMatch][1] = 1;  // tight=1: equal so far

    for (int pos = 0; pos < n; ++pos) {
        for (int match = 0; match < m; ++match) {
            for (int tight = 0; tight < 2; ++tight) {
                long long cur = dp[pos][match][tight];
                if (cur == 0) continue;
                int limit = tight ? (bound[pos] - 'a') : 25;
                for (int c = 0; c <= limit; ++c) {
                    int nmatch = match;
                    char ch = static_cast<char>('a' + c);
                    // KMP transition.
                    while (nmatch > 0 && evil[nmatch] != ch) nmatch = pi[nmatch - 1];
                    if (evil[nmatch] == ch) ++nmatch;
                    if (nmatch == m) continue;  // would form evil substring
                    int ntight = (tight && c == limit) ? 1 : 0;
                    dp[pos + 1][nmatch][ntight] =
                        (dp[pos + 1][nmatch][ntight] + cur) % MOD;
                }
            }
        }
    }

    long long ans = 0;
    for (int match = 0; match < m; ++match) {
        for (int tight = 0; tight < 2; ++tight) {
            ans = (ans + dp[n][match][tight]) % MOD;
        }
    }
    return ans;
}

int findGoodStringsImpl(int n, std::string s1, std::string s2, std::string evil) {
    (void)n;  // inferred from string lengths
    int m = evil.size();
    std::vector<int> pi = buildKmp(evil);

    auto f = [&](const std::string& bound) -> long long {
        return countLe(bound, evil, pi, 0);
    };

    long long f2 = f(s2);
    long long f1 = f(s1);

    // Check if s1 itself contains evil.
    bool s1Good = true;
    {
        int match = 0;
        for (char ch : s1) {
            while (match > 0 && evil[match] != ch) match = pi[match - 1];
            if (evil[match] == ch) ++match;
            if (match == m) { s1Good = false; break; }
        }
    }

    long long ans = (f2 - f1 + (s1Good ? 1 : 0)) % MOD;
    if (ans < 0) ans += MOD;
    return static_cast<int>(ans);
}

}  // namespace

FindAllGoodStringsSolution::FindAllGoodStringsSolution() {
    setMetaInfo({.id = 1397,
                 .title = "Find All Good Strings",
                 .url = "https://leetcode.com/problems/find-all-good-strings/"});

    registerStrategy(
        {.name = "digit-dp-kmp",
         .expected = "Accepted",
         .time_complexity = "O(n*m*26)",
         .space_complexity = "O(n*m)",
         .tags = {"String", "Dynamic Programming", "String Matching"},
         .notes = "Count strings <= s2 and <= s1 via digit-DP with tight bound; use KMP automaton to forbid evil substring; answer = f(s2) - f(s1) + isGood(s1)."},
        findGoodStringsImpl);
}

}  // namespace problem_1397
}  // namespace leetcode
