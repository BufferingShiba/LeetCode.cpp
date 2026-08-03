#include "leetcode/problems/selling-pieces-of-wood.h"

#include <algorithm>
#include <cstdint>
#include <vector>

namespace leetcode::problem_2312 {

namespace {

long long sellingWoodImpl(int m, int n, std::vector<std::vector<int>>& prices) {
    // dp[h][w] = max money obtainable from a h x w piece.
    std::vector<std::vector<long long>> dp(m + 1,
                                            std::vector<long long>(n + 1, 0));

    // Initialize with direct selling price (or keep 0 if not listed).
    for (const auto& p : prices) {
        int h = p[0];
        int w = p[1];
        long long price = p[2];
        dp[h][w] = std::max(dp[h][w], price);
    }

    // Compute in increasing h and w order so sub-problems are already solved.
    for (int h = 1; h <= m; ++h) {
        for (int w = 1; w <= n; ++w) {
            // Horizontal cuts.
            for (int k = 1; k < h; ++k) {
                dp[h][w] = std::max(dp[h][w], dp[k][w] + dp[h - k][w]);
            }
            // Vertical cuts.
            for (int k = 1; k < w; ++k) {
                dp[h][w] = std::max(dp[h][w], dp[h][k] + dp[h][w - k]);
            }
        }
    }

    return dp[m][n];
}

}  // namespace

SellingPiecesOfWoodSolution::SellingPiecesOfWoodSolution() {
    this->setMetaInfo({.id = 2312,
                       .title = "Selling Pieces of Wood",
                       .url = "https://leetcode.com/problems/selling-pieces-of-wood/"});
    this->registerStrategy(
        {.name = "dp",
         .expected = "Accepted",
         .time_complexity = "O(m*n*(m+n))",
         .space_complexity = "O(m*n)",
         .tags = {"Array", "Dynamic Programming", "Memoization"}},
        [](int m, int n, std::vector<std::vector<int>>& prices) -> long long {
            return sellingWoodImpl(m, n, prices);
        });
}

long long SellingPiecesOfWoodSolution::sellingWood(int m, int n,
                                                   std::vector<std::vector<int>>& prices) {
    return getSolution()(m, n, prices);
}

}  // namespace leetcode::problem_2312
