#include <cstdint>

#include "leetcode/problems/find-the-original-typed-string-ii.h"

namespace leetcode {
namespace problem_3333 {
namespace {

constexpr int kMod = 1000000007;

int possibleStringCountImpl(const std::string& word, int k) {
  // Run-length encode word.
  std::vector<int> runs;
  int n = static_cast<int>(word.size());
  for (int i = 0; i < n;) {
    int j = i;
    while (j < n && word[j] == word[i]) ++j;
    runs.push_back(j - i);
    i = j;
  }

  const int m = static_cast<int>(runs.size());

  // Total number of ways = product of len[i] (choose 1..len[i] per block).
  int64_t total = 1;
  for (int len : runs) total = total * len % kMod;

  // If minimal original length (m, one char per block) >= k, all ways valid.
  if (m >= k) return static_cast<int>(total);

  // Count invalid ways: original length < k.
  // extra_i = chosen_i - 1 in [0, len[i]-1], need sum(extra) <= k - m - 1.
  const int limit = k - m - 1;  // maximum allowed extra sum for invalid.

  // f[j] = number of ways with sum of extra == j.
  std::vector<int> f(limit + 1, 0);
  f[0] = 1;

  int64_t invalid = 0;
  for (int len : runs) {
    int w = len;  // extra range [0, w-1]
    std::vector<int> g(limit + 1, 0);
    int64_t run = 0;
    for (int j = 0; j <= limit; ++j) {
      run += f[j];
      if (run >= static_cast<int64_t>(kMod)) run -= kMod;
      if (j - w >= 0) {
        run -= f[j - w];
        if (run < 0) run += kMod;
      }
      g[j] = static_cast<int>(run);
    }
    f.swap(g);
  }

  for (int v : f) invalid = (invalid + v) % kMod;

  int64_t ans = (total - invalid) % kMod;
  if (ans < 0) ans += kMod;
  return static_cast<int>(ans);
}

}  // namespace

FindTheOriginalTypedStringIiSolution::FindTheOriginalTypedStringIiSolution() {
  setMetaInfo({.id = 3333,
               .title = "Find the Original Typed String II",
               .url = "https://leetcode.com/problems/find-the-original-typed-string-ii/"});
  registerStrategy(
      {.name = "bounded-knapsack-prefix-sum",
       .expected = "Accepted",
       .time_complexity = "O(n + m*k)",
       .space_complexity = "O(k)",
       .tags = {"String", "Dynamic Programming", "Prefix Sum"}},
      possibleStringCountImpl);
}

int FindTheOriginalTypedStringIiSolution::possibleStringCount(std::string word, int k) {
  return getSolution()(std::move(word), k);
}

}  // namespace problem_3333
}  // namespace leetcode
