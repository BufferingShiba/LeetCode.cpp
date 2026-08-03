#include "leetcode/problems/find-the-n-th-value-after-k-seconds.h"

namespace leetcode {
namespace problem_3179 {

namespace {

constexpr long long kMod = 1000000007LL;

// Prefix-sum simulation: each second each element becomes the running
// prefix sum. After k seconds, a[n-1] equals C(n+k-1, k) mod 1e9+7.
int valueAfterKSecondsImpl(int n, int k) {
  std::vector<long long> a(static_cast<size_t>(n), 1LL);
  for (int sec = 0; sec < k; ++sec) {
    for (int i = 1; i < n; ++i) {
      a[static_cast<size_t>(i)] =
          (a[static_cast<size_t>(i)] + a[static_cast<size_t>(i - 1)]) % kMod;
    }
  }
  return static_cast<int>(a[static_cast<size_t>(n - 1)]);
}

}  // namespace

FindTheNThValueAfterKSecondsSolution::FindTheNThValueAfterKSecondsSolution() {
  setMetaInfo({.id = 3179,
               .title = "Find the N-th Value After K Seconds",
               .url = "https://leetcode.com/problems/find-the-n-th-value-after-k-seconds/"});
  registerStrategy(
      {.name = "PrefixSum",
       .expected = "Accepted",
       .time_complexity = "O(n*k)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Simulation", "Prefix Sum"}},
      valueAfterKSecondsImpl);
}

int FindTheNThValueAfterKSecondsSolution::valueAfterKSeconds(int n, int k) {
  return getSolution()(n, k);
}

}  // namespace problem_3179
}  // namespace leetcode
