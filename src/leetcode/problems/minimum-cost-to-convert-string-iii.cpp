#include "leetcode/problems/minimum-cost-to-convert-string-iii.h"

#include <limits>

namespace leetcode {
namespace problem_3995 {

namespace {

int minCostImpl(std::string source, std::string target,
                std::vector<std::vector<std::string>>& rules,
                std::vector<int>& costs) {
    const int n = static_cast<int>(source.size());
    const int m = static_cast<int>(rules.size());
    const int INF = std::numeric_limits<int>::max() / 4;

    // dp[i] = minimum cost to convert suffix starting at position i.
    std::vector<long long> dp(n + 1, INF);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; --i) {
        // Option 1: leave position i untouched if chars already match.
        if (source[i] == target[i]) {
            dp[i] = std::min(dp[i], dp[i + 1]);
        }

        // Option 2: try each rule starting exactly at position i.
        for (int r = 0; r < m; ++r) {
            const std::string& pattern = rules[r][0];
            const std::string& replacement = rules[r][1];
            const int k = static_cast<int>(pattern.size());
            if (i + k > n) continue;

            long long extra = costs[r];
            bool ok = true;
            for (int j = 0; j < k; ++j) {
                char pch = pattern[j];
                if (pch == '*') {
                    ++extra;
                } else if (pch != source[i + j]) {
                    ok = false;
                    break;
                }
                if (replacement[j] != target[i + j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            dp[i] = std::min(dp[i], extra + dp[i + k]);
        }
    }

    return dp[0] >= INF ? -1 : static_cast<int>(dp[0]);
}

}  // namespace

MinimumCostToConvertStringIiiSolution::MinimumCostToConvertStringIiiSolution() {
    setMetaInfo({.id = 3995,
                 .title = "Minimum Cost to Convert String III",
                 .url = "https://leetcode.com/problems/minimum-cost-to-convert-string-iii/"});
    registerStrategy({.name = "suffix-dp",
                      .expected = "Accepted",
                      .time_complexity = "O(n * m * L)",
                      .space_complexity = "O(n)",
                      .tags = {"dynamic-programming"}},
                     minCostImpl);
}

int MinimumCostToConvertStringIiiSolution::minCost(
    std::string source, std::string target,
    std::vector<std::vector<std::string>>& rules,
    std::vector<int>& costs) {
    return getSolution()(std::move(source), std::move(target), rules, costs);
}

}  // namespace problem_3995
}  // namespace leetcode
