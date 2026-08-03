#include "leetcode/problems/minimum-difficulty-of-a-job-schedule.h"

#include <algorithm>
#include <climits>
#include <vector>

namespace leetcode {
namespace problem_1335 {

namespace {

int minDifficultyImpl(std::vector<int>& jobDifficulty, int d) {
    int n = static_cast<int>(jobDifficulty.size());
    if (n < d) {
        return -1;
    }

    // dp[i][k] = min difficulty for first i jobs in k days
    // We use 1-indexed for convenience: dp[0][0] = 0
    const int kInf = INT_MAX / 2;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(d + 1, kInf));
    dp[0][0] = 0;

    for (int k = 1; k <= d; ++k) {
        for (int i = k; i <= n; ++i) {
            int maxInSegment = 0;
            // j is the start of the last segment (0-indexed),
            // the last segment covers jobs[j .. i-1]
            for (int j = i - 1; j >= k - 1; --j) {
                maxInSegment = std::max(maxInSegment, jobDifficulty[j]);
                if (dp[j][k - 1] != kInf) {
                    dp[i][k] = std::min(dp[i][k], dp[j][k - 1] + maxInSegment);
                }
            }
        }
    }

    return dp[n][d] == kInf ? -1 : dp[n][d];
}

}  // namespace

int MinimumDifficultyOfAJobScheduleSolution::minDifficulty(
    std::vector<int>& jobDifficulty, int d) {
    return getSolution()(jobDifficulty, d);
}

MinimumDifficultyOfAJobScheduleSolution::MinimumDifficultyOfAJobScheduleSolution() {
    setMetaInfo({.id = 1335,
                 .title = "Minimum Difficulty of a Job Schedule",
                 .url = "https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/"});

    registerStrategy(
        StrategyMetadata{
            .name = "DP",
            .expected = "Accepted",
            .time_complexity = "O(n^2 * d)",
            .space_complexity = "O(n * d)",
            .tags = {"Array", "Dynamic Programming"}},
        minDifficultyImpl);
}

}  // namespace problem_1335
}  // namespace leetcode
