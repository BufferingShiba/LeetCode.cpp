#include "leetcode/problems/smallest-good-base.h"

#include <cstdint>
#include <string>

namespace leetcode {
namespace problem_483 {

namespace {

using i128 = __int128;

// Computes the eval of the geometric series 1 + k + k^2 + ... + k^m.
// Returns -1 if it overflows the given limit n.
i128 seriesValue(i128 k, int m, i128 limit) {
  i128 val = 1;
  i128 term = 1;
  for (int i = 0; i < m; ++i) {
    term *= k;
    if (term > limit) {
      return -1;  // overflow guard
    }
    val += term;
    if (val > limit) {
      return -1;
    }
  }
  return val;
}

// Finds the smallest base k >= 2 such that 1 + k + ... + k^m == n,
// or returns 0 if no such base exists.
i128 findBase(i128 n, int m) {
  // The sequence f(k) = 1 + k + ... + k^m is strictly increasing in k (for k>=1).
  // Binary search for the smallest k with f(k) >= n.
  i128 lo = 2;
  i128 hi = n;  // an upper bound: for m=1, k = n-1 works; use n as safe upper bound
  while (lo <= hi) {
    i128 mid = lo + (hi - lo) / 2;
    i128 val = seriesValue(mid, m, n);
    if (val == n) {
      return mid;
    } else if (val == -1 || val > n) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return 0;
}

std::string smallestGoodBaseImpl(std::string n) {
  i128 num = 0;
  for (char c : n) {
    num = num * 10 + (c - '0');
  }

  // The maximal possible length of the all-ones representation occurs at base 2.
  // 2^m <= num, find max m such that the representation length (m+1) >= 2.
  // For m = number of higher terms (terms after the constant 1).
  int max_m = 60;  // 2^60 > 10^18, safe upper bound
  // Compute the largest m with 2^m <= num - 1 (since 1+2+...+2^m = 2^(m+1)-1).
  i128 power = 1;
  max_m = 1;
  while (true) {
    // check if 2^(max_m+1) - 1 <= num
    if (((i128)1 << (max_m + 1)) - 1 <= num) {
      ++max_m;
    } else {
      break;
    }
  }
  // max_m now is the largest m with value(m, 2) <= num, i.e., 2^(m+1)-1 <= num.
  // (careful; recompute below)
  max_m = 0;
  i128 num2 = num;
  while (num2 >= 1) {
    num2 >>= 1;
    ++max_m;
  }
  // num < 2^max_m, so the longest representation (all ones) at base 2 has length <= max_m.
  // m (number of +1 terms beyond the constant) satisfies m+1 terms, 1+2+...+2^m = 2^(m+1)-1.
  // We iterate m from the largest down to 1; the first hit corresponds to the longest
  // possible representation, hence the smallest base.
  for (int m = max_m; m >= 1; --m) {
    // The series 1 + k + ... + k^m. For m >= 1, k >= 2.
    if ((i128)1 << (m + 1) > num + 1) {
      continue;  // even base 2 exceeds n; too long
    }
    i128 base = findBase(num, m);
    if (base >= 2) {
      return std::to_string((long long)base);
    }
  }
  // Guaranteed to be found, but fallback: m=1 gives k = n-1.
  return std::to_string((long long)(num - 1));
}

}  // namespace

SmallestGoodBaseSolution::SmallestGoodBaseSolution() {
  setMetaInfo({483, "Smallest Good Base",
               "https://leetcode.com/problems/smallest-good-base/"});
  registerStrategy(
      {"MathBinarySearch", "Accepted", "O(m * log n)", "O(1)",
       {"Math", "Binary Search"}},
      smallestGoodBaseImpl);
}

std::string SmallestGoodBaseSolution::smallestGoodBase(std::string n) {
  return getSolution()(std::move(n));
}

}  // namespace problem_483
}  // namespace leetcode
