#include "leetcode/problems/count-good-integers-in-a-range.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3966 {

namespace {

using int64 = long long;

// Count the number of integers in [0, N] whose adjacent digit differences
// are all <= k. Uses digit DP over the decimal representation of N.
long long countGoodUpTo(long long N, int k) {
  std::string s = std::to_string(N);
  int n = static_cast<int>(s.size());

  // memo[pos][prev][started][tight] : -1 means not computed.
  // prev ranges in [-1, 9]; map to [0, 10] where 10 means "no previous digit".
  std::vector<std::vector<std::vector<std::vector<int64>>>> memo(
      n, std::vector<std::vector<std::vector<int64>>>(
             11, std::vector<std::vector<int64>>(
                     2, std::vector<int64>(2, -1))));

  std::function<int64(int, int, int, int)> dfs = [&](int pos, int prev, int started, int tight) -> int64 {
    if (pos == n) {
      return 1;  // finished building a valid number (including 0 / empty)
    }
    int64& cache = memo[pos][prev][started][tight];
    if (cache != -1) return cache;

    int limit = tight ? (s[pos] - '0') : 9;
    int64 res = 0;
    for (int d = 0; d <= limit; ++d) {
      int ntight = tight && (d == limit) ? 1 : 0;
      if (!started) {
        // Leading zero: not started yet.
        if (d == 0) {
          res += dfs(pos + 1, 10, 0, ntight);
        } else {
          // Start the number with digit d.
          res += dfs(pos + 1, d, 1, ntight);
        }
      } else {
        // Already started; enforce adjacent difference constraint.
        if (std::abs(d - prev) <= k) {
          res += dfs(pos + 1, d, 1, ntight);
        }
      }
    }
    cache = res;
    return res;
  };

  return dfs(0, 10, 0, 1);
}

long long goodIntegersImpl(long long l, long long r, int k) {
  return countGoodUpTo(r, k) - countGoodUpTo(l - 1, k);
}

}  // namespace

CountGoodIntegersInARangeSolution::CountGoodIntegersInARangeSolution() {
  setMetaInfo({.id = 3966,
               .title = "Count Good Integers in a Range",
               .url = "https://leetcode.com/problems/count-good-integers-in-a-range/"});
  registerStrategy(
      {.name = "digit-dp",
       .expected = "Accepted",
       .time_complexity = "O(10 * digits^2 * 4)",
       .space_complexity = "O(digits * 11 * 2 * 2)",
       .tags = {"digit-dp", "counting"}},
      goodIntegersImpl);
}

long long CountGoodIntegersInARangeSolution::goodIntegers(long long l, long long r, int k) {
  return getSolution()(l, r, k);
}

}  // namespace problem_3966
}  // namespace leetcode
