#include "leetcode/problems/minimum-non-zero-product-of-the-array-elements.h"

namespace leetcode {
namespace problem_1969 {
namespace {

constexpr long long kMod = 1000000007LL;

long long powMod(long long base, long long exp, long long mod) {
  long long result = 1 % mod;
  base %= mod;
  while (exp > 0) {
    if (exp & 1) result = result * base % mod;
    base = base * base % mod;
    exp >>= 1;
  }
  return result;
}

// Minimum non-zero product = (2^p - 2)^(2^(p-1) - 1) * (2^p - 1) mod M.
int minNonZeroProductImpl(int p) {
  const long long maxVal = (1LL << p) - 1;  // 2^p - 1
  const long long value = maxVal - 1;       // 2^p - 2
  const long long exponent = (1LL << (p - 1)) - 1;  // 2^(p-1) - 1

  long long ans = powMod(value, exponent, kMod);
  ans = ans * (maxVal % kMod) % kMod;
  return static_cast<int>(ans);
}

}  // namespace

MinimumNonZeroProductOfTheArrayElementsSolution::
    MinimumNonZeroProductOfTheArrayElementsSolution() {
  setMetaInfo({1969, "Minimum Non-Zero Product of the Array Elements",
               "https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/"});
  registerStrategy(
      {"math-fast-exponentiation", "Accepted", "O(log p)", "O(1)",
       {"Math", "Greedy", "Recursion"},
       "Answer = (2^p-2)^(2^(p-1)-1) * (2^p-1) mod (1e9+7)"},
      [](int p) { return minNonZeroProductImpl(p); });
}

}  // namespace problem_1969
}  // namespace leetcode
