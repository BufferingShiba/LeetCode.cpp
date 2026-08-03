#include "leetcode/problems/longest-duplicate-substring.h"

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_1044 {

namespace {

std::string longestDupSubstringImpl(std::string s) {
  int n = static_cast<int>(s.size());
  if (n < 2) return "";

  const long long MOD1 = 1000000007LL;
  const long long MOD2 = 1000000009LL;
  const long long BASE = 31LL;

  // Precompute powers of BASE modulo MOD1 and MOD2
  std::vector<long long> pow1(n), pow2(n);
  pow1[0] = 1;
  pow2[0] = 1;
  for (int i = 1; i < n; ++i) {
    pow1[i] = (pow1[i - 1] * BASE) % MOD1;
    pow2[i] = (pow2[i - 1] * BASE) % MOD2;
  }

  // Returns the starting index of any duplicate substring of length L,
  // or -1 if none exists.
  auto hasDuplicateOfLength = [&](int L) -> int {
    if (L == 0) return -1;
    std::unordered_map<std::uint64_t, int> seen;

    long long h1 = 0;
    long long h2 = 0;

    // Hash of the first window s[0 .. L-1]
    for (int i = 0; i < L; ++i) {
      int val = s[i] - 'a' + 1;
      h1 = (h1 * BASE + val) % MOD1;
      h2 = (h2 * BASE + val) % MOD2;
    }
    seen[((std::uint64_t)h1 << 32) | (std::uint64_t)h2] = 0;

    // Slide the window
    for (int i = L; i < n; ++i) {
      int outVal = s[i - L] - 'a' + 1;
      int inVal = s[i] - 'a' + 1;

      // Remove leading character, shift, add trailing character
      h1 = (h1 - outVal * pow1[L - 1] % MOD1 + MOD1) % MOD1;
      h1 = (h1 * BASE + inVal) % MOD1;

      h2 = (h2 - outVal * pow2[L - 1] % MOD2 + MOD2) % MOD2;
      h2 = (h2 * BASE + inVal) % MOD2;

      std::uint64_t key =
          ((std::uint64_t)h1 << 32) | (std::uint64_t)h2;

      auto it = seen.find(key);
      if (it != seen.end()) {
        int pos = it->second;
        // Verify to avoid hash collisions (extremely rare with double hash)
        if (s.compare(pos, L, s, i - L + 1, L) == 0) {
          return pos;
        }
      }
      seen[key] = i - L + 1;
    }

    return -1;
  };

  int lo = 1;
  int hi = n - 1;
  std::string ans;

  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    int pos = hasDuplicateOfLength(mid);
    if (pos != -1) {
      ans = s.substr(pos, mid);
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  return ans;
}

}  // namespace

LongestDuplicateSubstringSolution::LongestDuplicateSubstringSolution() {
  setMetaInfo({.id = 1044,
               .title = "Longest Duplicate Substring",
               .url = "https://leetcode.com/problems/longest-duplicate-substring/"});

  registerStrategy(
      {.name = "BinarySearchRollingHash",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"String", "Binary Search", "Sliding Window", "Rolling Hash",
                "Hash Function"}},
      longestDupSubstringImpl);
}

std::string LongestDuplicateSubstringSolution::longestDupSubstring(
    std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_1044
}  // namespace leetcode
