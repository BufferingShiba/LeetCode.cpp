#include "leetcode/problems/direction-assignments-with-exactly-k-visible-people.h"

namespace leetcode {
namespace problem_3881 {

namespace {

constexpr int MOD = 1000000007;

long long modPow(long long base, long long exp, long long mod) {
  long long result = 1 % mod;
  base %= mod;
  while (exp > 0) {
    if (exp & 1) result = result * base % mod;
    base = base * base % mod;
    exp >>= 1;
  }
  return result;
}

int countVisiblePeopleImpl(int n, int pos, int k) {
  (void)pos;
  // Visible count = (people to the left choosing 'L') + (people to the right choosing 'R').
  // By Vandermonde's convolution, number of ways to see exactly k people is
  // C(pos, a) * C(n-1-pos, k-a) summed over a, which equals C(n-1, k).
  // The person at pos picks 'L' or 'R' freely: factor of 2.
  if (k < 0 || k > n - 1) return 0;

  int maxN = n - 1;
  std::vector<long long> fact(maxN + 1, 1);
  for (int i = 1; i <= maxN; ++i) fact[i] = fact[i - 1] * i % MOD;
  std::vector<long long> invFact(maxN + 1, 1);
  invFact[maxN] = modPow(fact[maxN], MOD - 2, MOD);
  for (int i = maxN; i >= 1; --i) invFact[i - 1] = invFact[i] * i % MOD;

  auto comb = [&](int a, int b) -> long long {
    if (b < 0 || b > a) return 0;
    return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
  };

  long long ways = comb(maxN, k);
  long long ans = ways * 2 % MOD;
  return static_cast<int>(ans);
}

}  // namespace

DirectionAssignmentsWithExactlyKVisiblePeopleSolution::
    DirectionAssignmentsWithExactlyKVisiblePeopleSolution() {
  setMetaInfo({.id = 3881,
               .title = "Direction Assignments with Exactly K Visible People",
               .url = "https://leetcode.com/problems/direction-assignments-with-exactly-k-visible-people/"});
  registerStrategy(
      {.name = "Combinatorics",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Math", "Combinatorics"}},
      countVisiblePeopleImpl);
}

int DirectionAssignmentsWithExactlyKVisiblePeopleSolution::countVisiblePeople(
    int n, int pos, int k) {
  return getSolution()(n, pos, k);
}

}  // namespace problem_3881
}  // namespace leetcode
