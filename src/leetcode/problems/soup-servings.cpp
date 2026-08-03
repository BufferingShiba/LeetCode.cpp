#include "leetcode/problems/soup-servings.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_808 {

namespace {

double soupServingsImpl(int n) {
  // For large n, the probability is essentially 1.0.
  // n >= 5000 corresponds to m >= 200 scaled units;
  // the error is well below 1e-5.
  if (n >= 5000) {
    return 1.0;
  }

  // Scale to units of 25 mL (round up).
  int m = (n + 24) / 25;

  // dp[a][b] = answer when we have a units of A and b units of B
  // (each unit = 25 mL). We need dp[m][m].
  std::vector<std::vector<double>> dp(m + 1, std::vector<double>(m + 1, 0.0));

  for (int a = 0; a <= m; ++a) {
    for (int b = 0; b <= m; ++b) {
      if (a == 0 && b == 0) {
        dp[a][b] = 0.5;
      } else if (a == 0) {
        dp[a][b] = 1.0;
      } else if (b == 0) {
        dp[a][b] = 0.0;
      } else {
        dp[a][b] = 0.25 * (
            dp[std::max(0, a - 4)][b] +
            dp[std::max(0, a - 3)][std::max(0, b - 1)] +
            dp[std::max(0, a - 2)][std::max(0, b - 2)] +
            dp[std::max(0, a - 1)][std::max(0, b - 3)]);
      }
    }
  }

  return dp[m][m];
}

}  // namespace

SoupServingsSolution::SoupServingsSolution() {
  setMetaInfo({.id = 808,
               .title = "Soup Servings",
               .url = "https://leetcode.com/problems/soup-servings/"});
  registerStrategy(
      {.name = "DP with threshold",
       .expected = "Accepted",
       .time_complexity = "O(m^2)",
       .space_complexity = "O(m^2)",
       .tags = {"Math", "Dynamic Programming", "Probability and Statistics"}},
      soupServingsImpl);
}

double SoupServingsSolution::soupServings(int n) {
  return getSolution()(n);
}

}  // namespace problem_808
}  // namespace leetcode
