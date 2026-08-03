#include "leetcode/problems/arranging-coins.h"

#include <cmath>

namespace leetcode::problem_441 {

namespace {

// Math: the k-th row needs k coins; rows 1..k need k*(k+1)/2 coins total.
// Solve k*(k+1)/2 <= n  =>  k = floor((sqrt(8n+1) - 1) / 2).
int arrangeCoinsImpl(int n) {
  long long m = static_cast<long long>(n);
  long long k = static_cast<long long>(
      (std::sqrt(static_cast<double>(8 * m + 1)) - 1.0) / 2.0);
  // Double-check due to floating point; adjust by at most 1-2 in either
  // direction using the exact formula k*(k+1)/2 <= n.
  while (k * (k + 1) / 2 <= m) {
    ++k;
  }
  --k;
  while (k > 0 && k * (k + 1) / 2 > m) {
    --k;
  }
  return static_cast<int>(k);
}

}  // namespace

ArrangingCoinsSolution::ArrangingCoinsSolution() {
  setMetaInfo({
      .id = 441,
      .title = "Arranging Coins",
      .url = "https://leetcode.com/problems/arranging-coins/",
  });
  registerStrategy(
      {
          .name = "Math",
          .expected = "Accepted",
          .time_complexity = "O(1)",
          .space_complexity = "O(1)",
          .tags = {"Math", "Binary Search"},
      },
      arrangeCoinsImpl);
}

int ArrangingCoinsSolution::arrangeCoins(int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_441
