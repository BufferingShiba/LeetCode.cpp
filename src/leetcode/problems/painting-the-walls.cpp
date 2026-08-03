#include "leetcode/problems/painting-the-walls.h"

#include <algorithm>

namespace leetcode::problem_2742 {

namespace {

// 0/1 knapsack: treat choosing wall i as an item with "weight" = time[i] + 1
// (paid paints 1 wall while free painter handles `time[i]` walls), and
// "cost" = cost[i]. We need total covered walls >= n with minimum total cost.
int paintWallsImpl(std::vector<int>& cost, std::vector<int>& time) {
    const int n = static_cast<int>(cost.size());
    constexpr long long INF = 1e18;

    // dp[j] = minimum cost to cover at least j walls.
    std::vector<long long> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        const int covered = time[i] + 1;
        // Iterate backwards to treat each wall as 0/1 item.
        for (int j = n; j >= 0; --j) {
            if (dp[j] >= INF) continue;
            int nj = std::min(n, j + covered);
            dp[nj] = std::min(dp[nj], dp[j] + cost[i]);
        }
    }

    return static_cast<int>(dp[n]);
}

}  // namespace

PaintingTheWallsSolution::PaintingTheWallsSolution() {
    setMetaInfo({
        .id = 2742,
        .title = "Painting the Walls",
        .url = "https://leetcode.com/problems/painting-the-walls/",
    });
    registerStrategy(
        {
            .name = "knapsack-dp",
            .expected = "Accepted",
            .time_complexity = "O(n^2)",
            .space_complexity = "O(n)",
            .tags = {"Array", "Dynamic Programming"},
        },
        paintWallsImpl);
}

int PaintingTheWallsSolution::paintWalls(std::vector<int>& cost, std::vector<int>& time) {
    return getSolution()(cost, time);
}

}  // namespace leetcode::problem_2742
