#include "leetcode/problems/lexicographically-smallest-palindromic-permutation-greater-than-target.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3734 {

namespace {

// Find the lexicographically smallest string > target_prefix that can be formed
// from the character multiset `need`. Returns empty string if impossible.
std::string nextGreater(const std::vector<int>& need,
                        const std::string& target_prefix) {
  int m = static_cast<int>(target_prefix.size());
  std::vector<int> tmp(26);

  // Scan from rightmost position to find the first place we can increase.
  for (int i = m - 1; i >= 0; --i) {
    // Try to match target_prefix[0..i-1] exactly.
    tmp = need;
    bool ok = true;
    for (int j = 0; j < i; ++j) {
      int c = target_prefix[j] - 'a';
      if (tmp[c] == 0) {
        ok = false;
        break;
      }
      tmp[c]--;
    }
    if (!ok) continue;

    // At position i, try a character strictly larger than target_prefix[i].
    int start = target_prefix[i] - 'a' + 1;
    for (int c = start; c < 26; ++c) {
      if (tmp[c] > 0) {
        tmp[c]--;
        std::string prefix =
            target_prefix.substr(0, i) + static_cast<char>('a' + c);
        // Fill the remaining positions with the smallest available characters.
        for (int j = i + 1; j < m; ++j) {
          for (int d = 0; d < 26; ++d) {
            if (tmp[d] > 0) {
              tmp[d]--;
              prefix += static_cast<char>('a' + d);
              break;
            }
          }
        }
        return prefix;
      }
    }
  }
  return "";
}

std::string solveImpl(std::string s, std::string target) {
  int n = static_cast<int>(s.size());
  int freq[26] = {0};
  for (char ch : s) {
    freq[ch - 'a']++;
  }

  int odd_count = 0;
  int odd_char = -1;
  for (int c = 0; c < 26; ++c) {
    if (freq[c] % 2 == 1) {
      odd_count++;
      odd_char = c;
    }
  }
  if (odd_count > 1) return "";

  int m = n / 2;
  std::vector<int> need(26);
  for (int c = 0; c < 26; ++c) {
    need[c] = freq[c] / 2;
  }

  std::string target_prefix = target.substr(0, m);

  // Can we match target_prefix exactly?
  bool can_match = true;
  std::vector<int> tmp = need;
  for (char ch : target_prefix) {
    int c = ch - 'a';
    if (tmp[c] == 0) {
      can_match = false;
      break;
    }
    tmp[c]--;
  }

  std::string prefix;
  if (can_match) {
    if (n % 2 == 0) {
      // Even length: palindrome == target when prefix == target_prefix.
      // We need strictly greater prefix.
      prefix = nextGreater(need, target_prefix);
      if (prefix.empty()) return "";
      return prefix + std::string(prefix.rbegin(), prefix.rend());
    } else {
      // Odd length: middle character can break the tie.
      if (odd_char > target[m] - 'a') {
        return target_prefix + static_cast<char>('a' + odd_char) +
               std::string(target_prefix.rbegin(), target_prefix.rend());
      } else {
        prefix = nextGreater(need, target_prefix);
        if (prefix.empty()) return "";
        return prefix + static_cast<char>('a' + odd_char) +
               std::string(prefix.rbegin(), prefix.rend());
      }
    }
  } else {
    prefix = nextGreater(need, target_prefix);
    if (prefix.empty()) return "";
    if (n % 2 == 0) {
      return prefix + std::string(prefix.rbegin(), prefix.rend());
    } else {
      return prefix + static_cast<char>('a' + odd_char) +
             std::string(prefix.rbegin(), prefix.rend());
    }
  }
}

}  // namespace

LexicographicallySmallestPalindromicPermutationGreaterThanTargetSolution::
    LexicographicallySmallestPalindromicPermutationGreaterThanTargetSolution() {
  setMetaInfo(
      {.id = 3734,
       .title = "Lexicographically Smallest Palindromic Permutation Greater Than "
                "Target",
       .url = "https://leetcode.com/problems/"
              "lexicographically-smallest-palindromic-permutation-greater-than-"
              "target/"});
  registerStrategy(
      {.name = "greedy_next_permutation",
       .expected = "Accepted",
       .time_complexity = "O(n * 26)",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String", "Enumeration"}},
      solveImpl);
}

std::string LexicographicallySmallestPalindromicPermutationGreaterThanTargetSolution::
    lexPalindromicPermutation(std::string s, std::string target) {
  return getSolution()(std::move(s), std::move(target));
}

}  // namespace problem_3734
}  // namespace leetcode
