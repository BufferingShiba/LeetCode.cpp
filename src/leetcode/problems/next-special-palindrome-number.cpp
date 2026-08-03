#include "leetcode/problems/next-special-palindrome-number.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode::problem_3646 {

// ------------------------------------------------------------
// Build the smallest palindrome for a given digit frequency
// ------------------------------------------------------------
static std::string buildSmallest(const std::vector<int>& freq, int L) {
  std::string half;
  half.reserve(L / 2);
  for (int d = 1; d <= 9; ++d) {
    int pairs = freq[d] / 2;
    half.append(pairs, static_cast<char>('0' + d));
  }

  std::string result;
  result.reserve(L);
  result = half;

  if (L % 2 == 1) {
    for (int d = 1; d <= 9; ++d) {
      if (freq[d] % 2 == 1) {
        result.push_back(static_cast<char>('0' + d));
        break;
      }
    }
  }

  std::reverse(half.begin(), half.end());
  result += half;
  return result;
}

// ------------------------------------------------------------
// Given a digit frequency, construct the smallest palindrome
// strictly larger than s (same length L).
// Returns empty string when impossible.
// ------------------------------------------------------------
static std::string findNext(const std::string& s, std::vector<int> freq, int L) {
  int half = (L + 1) / 2;
  std::string prefix(half, ' ');

  // quick check: can we complete positions i..half-1 ?
  auto canComplete = [&](int i, const std::vector<int>& f, bool greater) -> bool {
    if (greater) return true;  // frequency always matches remaining slots

    // Try to match s[i..half-1] exactly; if we cannot match some digit,
    // see whether we can put a larger digit instead.
    std::vector<int> tmp = f;
    for (int p = i; p < half; ++p) {
      int need = (p == L - 1 - p) ? 1 : 2;
      int cur = s[p] - '0';
      if (cur >= 1 && cur <= 9 && tmp[cur] >= need) {
        tmp[cur] -= need;
        continue;
      }
      // try a larger digit
      for (int d2 = cur + 1; d2 <= 9; ++d2) {
        if (tmp[d2] >= need) return true;
      }
      return false;
    }
    return true;  // exactly matched s
  };

  std::string bestPal;

  std::function<bool(int, bool)> dfs = [&](int i, bool greater) -> bool {
    if (i == half) {
      // Build full palindrome from prefix
      std::string pal;
      pal.reserve(L);
      for (int p = 0; p < L / 2; ++p) pal.push_back(prefix[p]);
      if (L % 2 == 1) pal.push_back(prefix[half - 1]);
      for (int p = L / 2 - 1; p >= 0; --p) pal.push_back(prefix[p]);

      if (pal > s) {
        bestPal = std::move(pal);
        return true;
      }
      return false;
    }

    int lo = 1;
    if (!greater) lo = std::max(lo, s[i] - '0');

    for (int d = lo; d <= 9; ++d) {
      int need = (i == L - 1 - i) ? 1 : 2;
      if (freq[d] < need) continue;

      freq[d] -= need;
      prefix[i] = static_cast<char>('0' + d);
      bool new_greater = greater || (d > s[i] - '0');

      if (canComplete(i + 1, freq, new_greater)) {
        if (dfs(i + 1, new_greater)) return true;
      }

      freq[d] += need;  // backtrack
    }

    return false;
  };

  if (dfs(0, false)) return bestPal;
  return {};
}

// ------------------------------------------------------------
// Main strategy
// ------------------------------------------------------------
static long specialPalindromeImpl(long long n) {
  std::string s = std::to_string(n);
  int nLen = static_cast<int>(s.size());

  std::string best;
  std::vector<int> freq(10, 0);

  // Enumerate all non-empty subsets of {1..9}  (bit 0 -> digit 1, ..., bit 8 -> digit 9)
  for (int mask = 1; mask < (1 << 9); ++mask) {
    int oddCount = 0;
    int totalLen = 0;
    std::fill(freq.begin(), freq.end(), 0);

    for (int d = 1; d <= 9; ++d) {
      if (mask & (1 << (d - 1))) {
        freq[d] = d;
        totalLen += d;
        if (d % 2 == 1) ++oddCount;
      }
    }

    // Palindrome constraint: at most one odd-count digit
    if (oddCount > 1) continue;

    if (totalLen < nLen) continue;

    std::string cand;
    if (totalLen > nLen) {
      cand = buildSmallest(freq, totalLen);
    } else {
      cand = findNext(s, freq, totalLen);
    }

    if (cand.empty()) continue;

    if (best.empty() || cand.size() < best.size() ||
        (cand.size() == best.size() && cand < best)) {
      best = std::move(cand);
    }
  }

  return std::stoll(best);
}

// ------------------------------------------------------------
// Solution class
// ------------------------------------------------------------
NextSpecialPalindromeNumberSolution::NextSpecialPalindromeNumberSolution() {
  setMetaInfo({.id = 3646,
               .title = "Next Special Palindrome Number",
               .url = "https://leetcode.com/problems/next-special-palindrome-number/"});
  registerStrategy(
      {.name = "Backtracking",
       .expected = "Accepted",
       .time_complexity = "O(2^9 * L)",
       .space_complexity = "O(L)",
       .tags = {"Backtracking", "Bit Manipulation"}},
      specialPalindromeImpl);
}

long NextSpecialPalindromeNumberSolution::specialPalindrome(long long n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_3646
