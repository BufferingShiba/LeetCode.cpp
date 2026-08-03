#include "leetcode/problems/factorial-trailing-zeroes.h"

namespace leetcode {
namespace problem_172 {
namespace {

int trailingZeroesImpl(int n) {
  int count = 0;
  while (n > 0) {
    n /= 5;
    count += n;
  }
  return count;
}

}  // namespace

FactorialTrailingZeroesSolution::FactorialTrailingZeroesSolution() {
  setMetaInfo({.id = 172,
               .title = "Factorial Trailing Zeroes",
               .url =
                   "https://leetcode.com/problems/factorial-trailing-zeroes/"});
  registerStrategy(
      {.name = "prime-factor-5-count",
       .expected = "Accepted",
       .time_complexity = "O(log_5 n)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Counting"}},
      [](int n) { return trailingZeroesImpl(n); });
}

int FactorialTrailingZeroesSolution::trailingZeroes(int n) {
  return getSolution()(n);
}

}  // namespace problem_172
}  // namespace leetcode
