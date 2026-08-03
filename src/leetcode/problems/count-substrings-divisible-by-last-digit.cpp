#include "leetcode/problems/count-substrings-divisible-by-last-digit.h"

#include <cstring>

namespace leetcode::problem_3448 {

static long long countSubstringsImpl(std::string s) {
    int n = static_cast<int>(s.size());
    // dp[d][r]: count of substrings ending at current position with value % d == r
    // d ranges 1..9, r ranges 0..d-1; unused slots stay 0.
    int dp[10][10] = {};
    long long ans = 0;

    for (int j = 0; j < n; ++j) {
        int x = s[j] - '0';
        int ndp[10][10] = {};

        for (int d = 1; d <= 9; ++d) {
            // extend all existing substrings ending at j-1
            for (int r = 0; r < d; ++r) {
                int cnt = dp[d][r];
                if (cnt) {
                    int nr = (r * 10 + x) % d;
                    ndp[d][nr] += cnt;
                }
            }
            // the single-digit substring s[j..j]
            ndp[d][x % d] += 1;
        }

        std::memcpy(dp, ndp, sizeof(dp));

        if (x != 0) {
            ans += dp[x][0];
        }
    }

    return ans;
}

CountSubstringsDivisibleByLastDigitSolution::CountSubstringsDivisibleByLastDigitSolution() {
    setMetaInfo({.id = 3448,
                 .title = "Count Substrings Divisible By Last Digit",
                 .url = "https://leetcode.com/problems/count-substrings-divisible-by-last-digit/"});
    registerStrategy({.name = "DP with modular arithmetic",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(1)",
                      .tags = {"String", "Dynamic Programming"}},
                     countSubstringsImpl);
}

long long CountSubstringsDivisibleByLastDigitSolution::countSubstrings(std::string s) {
    return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_3448
