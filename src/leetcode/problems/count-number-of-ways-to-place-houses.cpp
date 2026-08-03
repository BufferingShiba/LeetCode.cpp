#include "leetcode/problems/count-number-of-ways-to-place-houses.h"

namespace leetcode {
namespace problem_2320 {

namespace {
constexpr long long kMod = 1000000007LL;
}

static int solution1(int n) {
  // For a single side of n plots with no two adjacent houses, the count f(n)
  // follows Fibonacci: f(0) = 1, f(1) = 2, f(k) = f(k-1) + f(k-2).
  // The two sides are independent, so the answer is f(n) * f(n) mod 1e9+7.
  long long a = 1;  // f(0)
  long long b = 2;  // f(1)
  for (int i = 2; i <= n; ++i) {
    long long cur = (a + b) % kMod;
    a = b;
    b = cur;
  }
  long long side = (n == 0) ? a : b;
  return static_cast<int>(side * side % kMod);
}

CountNumberOfWaysToPlaceHousesSolution::CountNumberOfWaysToPlaceHousesSolution() {
  setMetaInfo({
      .id = 2320,
      .title = "Count Number of Ways to Place Houses",
      .url = "https://leetcode.com/problems/count-number-of-ways-to-place-houses"
  });
  registerStrategy(
      {.name = "Fibonacci DP",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Dynamic Programming"}},
      solution1);
}

int CountNumberOfWaysToPlaceHousesSolution::countHousePlacements(int n) {
  return getSolution()(n);
}

}  // namespace problem_2320
}  // namespace leetcode
