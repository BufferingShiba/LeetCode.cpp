#include "leetcode/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls.h"

#include <vector>

namespace leetcode {
namespace problem_1467 {

static double getProbabilityImpl(std::vector<int>& balls) {
  int k = static_cast<int>(balls.size());
  int total = 0;
  for (int b : balls) total += b;
  int n = total / 2;

  // factorials up to 6
  double fact[7];
  fact[0] = 1.0;
  for (int i = 1; i <= 6; ++i) fact[i] = fact[i - 1] * i;
  double inv_fact[7];
  for (int i = 0; i <= 6; ++i) inv_fact[i] = 1.0 / fact[i];

  // dp[i][j][a][b] = after processing first i colors,
  //   j balls in box1,
  //   a colors entirely in box1 (x == balls[i]),
  //   b colors entirely in box2 (x == 0),
  //   sum of products of 1/(x! * (cnt-x)!) over assignments
  std::vector<std::vector<std::vector<std::vector<double>>>> dp(
      k + 1,
      std::vector<std::vector<std::vector<double>>>(
          n + 1,
          std::vector<std::vector<double>>(
              k + 1,
              std::vector<double>(k + 1, 0.0))));

  dp[0][0][0][0] = 1.0;

  for (int i = 0; i < k; ++i) {
    int cnt = balls[i];
    for (int j = 0; j <= n; ++j) {
      for (int a = 0; a <= i; ++a) {
        for (int b = 0; b <= i; ++b) {
          double cur = dp[i][j][a][b];
          if (cur == 0.0) continue;
          for (int x = 0; x <= cnt; ++x) {
            int nj = j + x;
            if (nj > n) break;
            int na = a + (x == cnt ? 1 : 0);
            int nb = b + (x == 0 ? 1 : 0);
            dp[i + 1][nj][na][nb] +=
                cur * inv_fact[x] * inv_fact[cnt - x];
          }
        }
      }
    }
  }

  double numerator = 0.0;
  double denominator = 0.0;
  for (int a = 0; a <= k; ++a) {
    for (int b = 0; b <= k; ++b) {
      double val = dp[k][n][a][b];
      denominator += val;
      if (a == b) {
        numerator += val;
      }
    }
  }

  return numerator / denominator;
}

double
ProbabilityOfATwoBoxesHavingTheSameNumberOfDistinctBallsSolution::getProbability(
    std::vector<int>& balls) {
  return getSolution()(balls);
}

ProbabilityOfATwoBoxesHavingTheSameNumberOfDistinctBallsSolution::
    ProbabilityOfATwoBoxesHavingTheSameNumberOfDistinctBallsSolution() {
  setMetaInfo(
      1467,
      "Probability of a Two Boxes Having The Same Number of Distinct Balls",
      "https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/");

  StrategyMetadata meta;
  meta.name = "DP";
  meta.expected = "Accepted";
  meta.time_complexity = "O(k * n * k^2 * max(balls[i]))";
  meta.space_complexity = "O(k * n * k^2)";
  meta.tags = {"Dynamic Programming", "Combinatorics"};
  registerStrategy(meta, getProbabilityImpl);
}

}  // namespace problem_1467
}  // namespace leetcode
