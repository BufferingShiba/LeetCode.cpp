#include "leetcode/problems/nth-magical-number.h"

namespace leetcode {
namespace problem_878 {
namespace {

long long gcd(long long x, long long y) {
  while (y) {
    long long t = x % y;
    x = y;
    y = t;
  }
  return x;
}

int nthMagicalNumberImpl(int n, int a, int b) {
  const long long MOD = 1000000007LL;
  long long g = gcd(a, b);
  long long lcm = (long long)a / g * b;

  long long lo = 0;
  long long hi = (long long)std::min(a, b) * n;
  while (lo < hi) {
    long long mid = lo + (hi - lo) / 2;
    long long cnt = mid / a + mid / b - mid / lcm;
    if (cnt < n) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return static_cast<int>(lo % MOD);
}

}  // namespace

NthMagicalNumberSolution::NthMagicalNumberSolution() {
  setMetaInfo({.id = 878, .title = "Nth Magical Number", .url = "https://leetcode.com/problems/nth-magical-number/"});
  registerStrategy(
      {.name = "binary-search", .expected = "Accepted", .time_complexity = "O(log(n * min(a,b)))", .space_complexity = "O(1)", .tags = {"Math", "Binary Search"}},
      nthMagicalNumberImpl);
}

int NthMagicalNumberSolution::nthMagicalNumber(int n, int a, int b) {
  return getSolution()(n, a, b);
}

}  // namespace problem_878
}  // namespace leetcode
