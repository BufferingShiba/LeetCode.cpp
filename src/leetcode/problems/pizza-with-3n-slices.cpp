#include "leetcode/problems/pizza-with-3n-slices.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_1388 {

namespace {

int maxSizeSlicesImpl(std::vector<int>& slices) {
    int m = static_cast<int>(slices.size());
    int n = m / 3;

    // Solve the linear version: pick n non-adjacent elements
    // from slices[start..end) to maximize sum.
    auto solve = [&](int start, int end) -> int {
        int len = end - start;
        // dp[i][j]: max sum picking j elements from first i elements
        // (1-indexed for convenience)
        constexpr int NEG_INF = -1'000'000'000;
        std::vector<std::vector<int>> dp(len + 1,
                                         std::vector<int>(n + 1, NEG_INF));
        for (int i = 0; i <= len; ++i) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j <= n; ++j) {
                // Option 1: skip the current element
                dp[i][j] = dp[i - 1][j];

                // Option 2: take the current element
                int prev = (i >= 2) ? dp[i - 2][j - 1]
                                    : (j == 1 ? 0 : NEG_INF);
                if (prev != NEG_INF) {
                    dp[i][j] = std::max(dp[i][j],
                                        prev + slices[start + i - 1]);
                }
            }
        }
        return dp[len][n];
    };

    // Case 1: exclude the first element (pick from slices[1..m-1])
    int ans1 = solve(1, m);
    // Case 2: exclude the last element  (pick from slices[0..m-2])
    int ans2 = solve(0, m - 1);

    return std::max(ans1, ans2);
}

}  // namespace

PizzaWith3nSlicesSolution::PizzaWith3nSlicesSolution() {
    setMetaInfo({.id = 1388,
                 .title = "Pizza With 3n Slices",
                 .url = "https://leetcode.com/problems/pizza-with-3n-slices/"});

    registerStrategy(
        {.name = "DP (Break Circle)",
         .expected = "Accepted",
         .time_complexity = "O(n^2)",
         .space_complexity = "O(n^2)",
         .tags = {"Dynamic Programming", "Array"}},
        maxSizeSlicesImpl);
}

int PizzaWith3nSlicesSolution::maxSizeSlices(std::vector<int>& slices) {
    return getSolution()(slices);
}

}  // namespace problem_1388
}  // namespace leetcode
