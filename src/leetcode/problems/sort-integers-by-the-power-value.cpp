#include "leetcode/problems/sort-integers-by-the-power-value.h"

#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_1387 {

namespace {

// Compute the Collatz power (steps to reach 1) with memoization.
// Uses long long internally to safely handle intermediate 3x+1 values.
int powerValue(long long x, std::unordered_map<long long, int>& memo) {
  if (x == 1) return 0;
  auto it = memo.find(x);
  if (it != memo.end()) return it->second;
  int steps;
  if (x % 2 == 0) {
    steps = 1 + powerValue(x / 2, memo);
  } else {
    steps = 1 + powerValue(3 * x + 1, memo);
  }
  memo[x] = steps;
  return steps;
}

int getKthImpl(int lo, int hi, int k) {
  std::unordered_map<long long, int> memo;
  memo[1] = 0;

  std::vector<std::pair<int, int>> vals;
  vals.reserve(hi - lo + 1);
  for (int x = lo; x <= hi; ++x) {
    int p = powerValue(x, memo);
    vals.emplace_back(p, x);
  }

  std::sort(vals.begin(), vals.end());
  return vals[k - 1].second;
}

}  // namespace

SortIntegersByThePowerValueSolution::SortIntegersByThePowerValueSolution() {
  setMetaInfo({.id = 1387,
               .title = "Sort Integers by The Power Value",
               .url = "https://leetcode.com/problems/sort-integers-by-the-power-value/"});
  registerStrategy(
      {.name = "memoizedSort",
       .expected = "Accepted",
       .time_complexity = "O(N log N + C)",
       .space_complexity = "O(C)",
       .tags = {"Memoization", "Sorting", "Collatz"},
       .notes = "Memoize Collatz power values, sort by (power, value), return k-th."},
      getKthImpl);
}

int SortIntegersByThePowerValueSolution::getKth(int lo, int hi, int k) {
  return getSolution()(lo, hi, k);
}

}  // namespace problem_1387
}  // namespace leetcode
