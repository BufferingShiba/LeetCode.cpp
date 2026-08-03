#include "leetcode/problems/smallest-value-after-replacing-with-sum-of-prime-factors.h"

namespace leetcode::problem_2507 {

namespace {

long long sumPrimeFactors(int n) {
  long long sum = 0;
  for (int p = 2; 1LL * p * p <= n; ++p) {
    while (n % p == 0) {
      sum += p;
      n /= p;
    }
  }
  if (n > 1) {
    sum += n;  // remaining prime factor
  }
  return sum;
}

int smallestValueImpl(int n) {
  while (true) {
    long long s = sumPrimeFactors(n);
    if (s >= n) {
      break;
    }
    n = static_cast<int>(s);
  }
  return n;
}

}  // namespace

SmallestValueAfterReplacingWithSumOfPrimeFactorsSolution::
    SmallestValueAfterReplacingWithSumOfPrimeFactorsSolution() {
  setMetaInfo({.id = 2507,
               .title = "Smallest Value After Replacing With Sum of Prime Factors",
               .url =
                   "https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/"});
  registerStrategy({.name = "prime-factor-simulation",
                    .expected = "Accepted",
                    .time_complexity = "O(sqrt(n) * iterations)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "Simulation", "Number Theory"}},
                   smallestValueImpl);
}

int SmallestValueAfterReplacingWithSumOfPrimeFactorsSolution::smallestValue(
    int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_2507
