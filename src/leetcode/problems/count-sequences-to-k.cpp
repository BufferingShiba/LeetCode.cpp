#include "leetcode/problems/count-sequences-to-k.h"

#include <array>
#include <functional>
#include <unordered_map>

namespace leetcode {
namespace problem_3850 {

namespace {

int countSequencesImpl(std::vector<int>& nums, long long k) {
  // Factor k into primes 2,3,5. If k has a prime factor > 5, answer is 0
  // because val's primes can only come from {2,3,5} via mult/div and k itself.
  long long kk = k;
  int e2 = 0, e3 = 0, e5 = 0;
  while (kk % 2 == 0) { kk /= 2; ++e2; }
  while (kk % 3 == 0) { kk /= 3; ++e3; }
  while (kk % 5 == 0) { kk /= 5; ++e5; }
  if (kk != 1) return 0;

  const int n = static_cast<int>(nums.size());
  // Exponent contribution of each nums[i] for primes {2,3,5}.
  std::vector<std::array<int, 3>> fac(n);
  for (int i = 0; i < n; ++i) {
    fac[i] = {0, 0, 0};
    int v = nums[i];
    while (v % 2 == 0) { v /= 2; ++fac[i][0]; }
    while (v % 3 == 0) { v /= 3; ++fac[i][1]; }
    while (v % 5 == 0) { v /= 5; ++fac[i][2]; }
  }

  // Ratio val/k = 2^e2 * 3^e3 * 5^e5. Start with val=1 => ratio = 1/k
  // => exponents = (-e2, -e3, -e5). Goal: (0,0,0).
  const long long OFF = 300;
  const long long BASE = 1024;
  std::unordered_map<long long, long long> memo;

  std::function<long long(int, int, int, int)> dfs =
      [&](int i, int a2, int a3, int a5) -> long long {
    if (i == n) {
      return (a2 == 0 && a3 == 0 && a5 == 0) ? 1 : 0;
    }
    long long key =
        (((long long)i * BASE + (a2 + OFF)) * BASE + (a3 + OFF)) * BASE +
        (a5 + OFF);
    auto it = memo.find(key);
    if (it != memo.end()) return it->second;

    long long res = 0;
    // Leave unchanged.
    res += dfs(i + 1, a2, a3, a5);
    // Multiply by nums[i].
    res += dfs(i + 1, a2 + fac[i][0], a3 + fac[i][1], a5 + fac[i][2]);
    // Divide by nums[i].
    res += dfs(i + 1, a2 - fac[i][0], a3 - fac[i][1], a5 - fac[i][2]);

    memo[key] = res;
    return res;
  };

  long long total = dfs(0, -e2, -e3, -e5);
  return static_cast<int>(total);
}

}  // namespace

CountSequencesToKSolution::CountSequencesToKSolution() {
  setMetaInfo({.id = 3850,
               .title = "Count Sequences to K",
               .url = "https://leetcode.com/problems/count-sequences-to-k/"});
  registerStrategy(
      {
          .name = "ExponentMemoDP",
          .expected = "Accepted",
          .time_complexity = "O(n * E2*E3*E5)",
          .space_complexity = "O(n * E2*E3*E5)",
          .tags = {"Dynamic Programming", "Memoization", "Math",
                   "Number Theory"},
          .notes =
              "Represent ratio val/k by exponents of primes {2,3,5}; memoized "
              "top-down DP over (i, e2, e3, e5).",
      },
      countSequencesImpl);
}

int CountSequencesToKSolution::countSequences(std::vector<int>& nums,
                                              long long k) {
  return getSolution()(nums, k);
}

}  // namespace problem_3850
}  // namespace leetcode
