#include "leetcode/problems/longest-palindrome-after-substring-concatenation-i.h"

#include <algorithm>
#include <string>

namespace leetcode {
namespace problem_3503 {

namespace {

int longestPalindromeImpl(std::string s, std::string t) {
  int n = static_cast<int>(s.size());
  int m = static_cast<int>(t.size());
  int ans = 1;  // at least a single character

  // Helper: check if s[l..r] is palindrome
  auto isPalindrome = [](const std::string& str, int l, int r) {
    while (l < r) {
      if (str[l] != str[r]) return false;
      ++l;
      --r;
    }
    return true;
  };

  // Case 1: palindrome entirely within s
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (isPalindrome(s, i, j)) {
        ans = std::max(ans, j - i + 1);
      }
    }
  }

  // Case 2: palindrome entirely within t
  for (int i = 0; i < m; ++i) {
    for (int j = i; j < m; ++j) {
      if (isPalindrome(t, i, j)) {
        ans = std::max(ans, j - i + 1);
      }
    }
  }

  // Case 3: cross palindrome s[i..j] + t[k..l]
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        for (int l = k; l < m; ++l) {
          int len = (j - i + 1) + (l - k + 1);
          if (len <= ans) continue;  // prune

          // Two-pointer check on the concatenated string
          int left = i;
          int right = l;
          bool ok = true;
          while (left <= j || right >= k) {
            // Character from the left side of concatenation
            char cl;
            if (left <= j) {
              cl = s[left];
            } else {
              cl = t[k + (left - j - 1)];
            }
            // Character from the right side of concatenation
            char cr;
            if (right >= k) {
              cr = t[right];
            } else {
              cr = s[j - (k - right - 1)];
            }
            if (cl != cr) {
              ok = false;
              break;
            }
            ++left;
            --right;
          }
          if (ok) {
            ans = len;
          }
        }
      }
    }
  }

  return ans;
}

}  // namespace

LongestPalindromeAfterSubstringConcatenationISolution::
    LongestPalindromeAfterSubstringConcatenationISolution() {
  setMetaInfo({.id = 3503,
               .title = "Longest Palindrome After Substring Concatenation I",
               .url = "https://leetcode.com/problems/longest-palindrome-after-substring-concatenation-i/"});

  registerStrategy(
      {.name = "brute_force",
       .expected = "Accepted",
       .time_complexity = "O(n^2 * m^2 * (n+m))",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String", "Enumeration"}},
      longestPalindromeImpl);
}

int LongestPalindromeAfterSubstringConcatenationISolution::longestPalindrome(
    std::string s, std::string t) {
  return getSolution()(s, t);
}

}  // namespace problem_3503
}  // namespace leetcode
