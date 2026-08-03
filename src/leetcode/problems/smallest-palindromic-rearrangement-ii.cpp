#include "leetcode/problems/smallest-palindromic-rearrangement-ii.h"
#include <cstring>

namespace leetcode {
namespace problem_3518 {

namespace {

// Compute the number of distinct permutations of the multiset defined by
// `counts` with total `n` elements, capped at `limit`.
// Returns min(actual_value, limit + 1).
long long cappedMultinomial(int n, const int counts[26], long long limit) {
  if (n == 0) return 1;
  long long result = 1;
  int remaining = n;
  for (int i = 0; i < 26; ++i) {
    int ci = counts[i];
    if (ci == 0) continue;

    // Compute C(remaining, ci) capped at `limit`
    int k = ci;
    if (k > remaining - k) k = remaining - k;
    long long binom = 1;
    for (int j = 0; j < k; ++j) {
      // Check if next binom value would exceed limit:
      // binom * (remaining - j) / (j + 1) > limit
      if (binom > limit) return limit + 1;
      // Equivalent to: binom * (remaining - j) > limit * (j + 1)
      if ((__int128)binom * (remaining - j) > (__int128)limit * (j + 1)) {
        return limit + 1;
      }
      binom = binom * (remaining - j) / (j + 1);
    }

    // Multiply result by binom, capped
    if (result > limit) return limit + 1;
    if ((__int128)result * binom > (__int128)limit) {
      return limit + 1;
    }
    result = result * binom;
    remaining -= ci;
  }
  return result;
}

std::string smallestPalindromeImpl(std::string s, int k) {
  int n = static_cast<int>(s.size());
  int cnt[26] = {0};
  for (char c : s) ++cnt[c - 'a'];

  int halfCnt[26];
  int m = n / 2;
  for (int i = 0; i < 26; ++i) halfCnt[i] = cnt[i] / 2;

  char middle = '\0';
  if (n % 2 == 1) {
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] % 2 == 1) {
        middle = static_cast<char>('a' + i);
        break;
      }
    }
  }

  long long kk = k;
  long long total = cappedMultinomial(m, halfCnt, kk);
  if (total < kk) return "";

  std::string half;
  half.reserve(m);
  int curCnt[26];
  std::memcpy(curCnt, halfCnt, sizeof(curCnt));
  int remaining = m;

  for (int pos = 0; pos < m; ++pos) {
    for (int c = 0; c < 26; ++c) {
      if (curCnt[c] == 0) continue;
      --curCnt[c];
      long long ways = cappedMultinomial(remaining - 1, curCnt, kk);
      if (ways >= kk) {
        half.push_back(static_cast<char>('a' + c));
        --remaining;
        break;
      } else {
        kk -= ways;
        ++curCnt[c];
      }
    }
  }

  std::string result;
  result.reserve(n);
  result = half;
  if (n % 2 == 1) result += middle;
  for (int i = m - 1; i >= 0; --i) result += half[i];
  return result;
}

}  // namespace

SmallestPalindromicRearrangementIiSolution::SmallestPalindromicRearrangementIiSolution() {
  setMetaInfo({.id = 3518,
               .title = "Smallest Palindromic Rearrangement II",
               .url = "https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/"});
  registerStrategy(
      {.name = "Combinatorial",
       .expected = "Accepted",
       .time_complexity = "O(n + m * |Σ|)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "Math", "String", "Combinatorics", "Counting"}},
      smallestPalindromeImpl);
}

std::string SmallestPalindromicRearrangementIiSolution::smallestPalindrome(std::string s, int k) {
  return getSolution()(s, k);
}

}  // namespace problem_3518
}  // namespace leetcode
