#include "leetcode/problems/prime-pairs-with-target-sum.h"

namespace leetcode {
namespace problem_2761 {

static vector<vector<int>> solution1(int n) {
  if (n < 4) return vector<vector<int>>();

  // Sieve of Eratosthenes: mark primes in [2, n].
  vector<bool> isPrime(n + 1, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i <= n; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  vector<vector<int>> res;
  for (int x = 2; 2 * x <= n; ++x) {
    int y = n - x;
    if (isPrime[x] && isPrime[y]) {
      res.push_back({x, y});
    }
  }
  return res;
}

PrimePairsWithTargetSumSolution::PrimePairsWithTargetSumSolution() {
  setMetaInfo({
      .id = 2761,
      .title = "Prime Pairs With Target Sum",
      .url = "https://leetcode.com/problems/prime-pairs-with-target-sum"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

vector<vector<int>> PrimePairsWithTargetSumSolution::findPrimePairs(int n) {
  return getSolution()(n);
}

}  // namespace problem_2761
}  // namespace leetcode
