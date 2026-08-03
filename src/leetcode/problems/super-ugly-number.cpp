#include "leetcode/problems/super-ugly-number.h"

#include <climits>
#include <vector>

namespace leetcode::problem_313 {

static int nthSuperUglyNumberImpl(int n, std::vector<int>& primes) {
  if (n == 1) {
    return 1;
  }

  int k = static_cast<int>(primes.size());
  std::vector<int> dp(n);
  std::vector<int> pointers(k, 0);
  dp[0] = 1;

  for (int i = 1; i < n; ++i) {
    int min_val = INT_MAX;
    for (int j = 0; j < k; ++j) {
      long long candidate = static_cast<long long>(dp[pointers[j]]) * primes[j];
      if (candidate < min_val) {
        min_val = static_cast<int>(candidate);
      }
    }
    dp[i] = min_val;

    for (int j = 0; j < k; ++j) {
      long long candidate = static_cast<long long>(dp[pointers[j]]) * primes[j];
      if (candidate == min_val) {
        ++pointers[j];
      }
    }
  }

  return dp[n - 1];
}

SuperUglyNumberSolution::SuperUglyNumberSolution() {
  setMetaInfo({.id = 313,
               .title = "Super Ugly Number",
               .url = "https://leetcode.com/problems/super-ugly-number/"});
  registerStrategy({.name = "DP with k pointers",
                    .expected = "Accepted",
                    .time_complexity = "O(n * k)",
                    .space_complexity = "O(n + k)",
                    .tags = {"Array", "Math", "Dynamic Programming"}},
                   nthSuperUglyNumberImpl);
}

int SuperUglyNumberSolution::nthSuperUglyNumber(int n, std::vector<int>& primes) {
  return getSolution()(n, primes);
}

}  // namespace leetcode::problem_313