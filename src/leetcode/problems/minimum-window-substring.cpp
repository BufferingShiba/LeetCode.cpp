#include "leetcode/problems/minimum-window-substring.h"

#include <algorithm>
#include <climits>
#include <string>

namespace leetcode {
namespace problem_76 {

namespace {

std::string minWindowImpl(std::string s, std::string t) {
  const int m = static_cast<int>(s.size());
  const int n = static_cast<int>(t.size());
  if (m < n) return "";

  int need[128] = {0};
  int required = 0;
  for (char c : t) {
    if (need[static_cast<unsigned char>(c)] == 0) {
      ++required;
    }
    ++need[static_cast<unsigned char>(c)];
  }

  int window[128] = {0};
  int have = 0;
  int min_len = INT_MAX;
  int start = 0;
  int l = 0;

  for (int r = 0; r < m; ++r) {
    unsigned char c = static_cast<unsigned char>(s[r]);
    ++window[c];
    if (need[c] > 0 && window[c] == need[c]) {
      ++have;
    }

    while (have == required) {
      int cur_len = r - l + 1;
      if (cur_len < min_len) {
        min_len = cur_len;
        start = l;
      }

      unsigned char cl = static_cast<unsigned char>(s[l]);
      --window[cl];
      if (need[cl] > 0 && window[cl] < need[cl]) {
        --have;
      }
      ++l;
    }
  }

  return (min_len == INT_MAX) ? "" : s.substr(start, min_len);
}

}  // namespace

MinimumWindowSubstringSolution::MinimumWindowSubstringSolution() {
  setMetaInfo({.id = 76,
               .title = "Minimum Window Substring",
               .url = "https://leetcode.com/problems/minimum-window-substring/"});

  registerStrategy(
      {.name = "sliding_window",
       .expected = "Accepted",
       .time_complexity = "O(m + n)",
       .space_complexity = "O(1)",
       .tags = {"hash-table", "string", "sliding-window"}},
      minWindowImpl);

  setDefaultStrategy();
}

std::string MinimumWindowSubstringSolution::minWindow(std::string s, std::string t) {
  return getSolution()(std::move(s), std::move(t));
}

}  // namespace problem_76
}  // namespace leetcode
