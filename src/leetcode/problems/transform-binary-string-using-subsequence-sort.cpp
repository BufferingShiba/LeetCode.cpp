#include "leetcode/problems/transform-binary-string-using-subsequence-sort.h"

#include <algorithm>

namespace leetcode {
namespace problem_3998 {

static std::vector<bool> transformStrImpl(const std::string& s,
                                          std::vector<std::string>& strs) {
  const int n = static_cast<int>(s.size());

  // prefix count of '0' in s
  std::vector<int> pref0_s(n);
  int cnt0_s = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') ++cnt0_s;
    pref0_s[i] = cnt0_s;
  }

  std::vector<bool> ans;
  ans.reserve(strs.size());

  for (const auto& qs : strs) {
    // count fixed zeros and question marks
    int fixed0 = 0;
    int qmarks = 0;
    for (char c : qs) {
      if (c == '0')
        ++fixed0;
      else if (c == '?')
        ++qmarks;
    }

    int need0 = cnt0_s - fixed0;
    if (need0 < 0 || need0 > qmarks) {
      ans.push_back(false);
      continue;
    }

    int pref0_t = 0;
    int remaining_need = need0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      char c = qs[i];
      if (c == '0') {
        ++pref0_t;
      } else if (c == '?') {
        if (remaining_need > 0) {
          ++pref0_t;
          --remaining_need;
        }
        // else: treat as '1', pref0_t unchanged
      }
      // c == '1': pref0_t unchanged

      if (pref0_t < pref0_s[i]) {
        ok = false;
        break;
      }
    }
    ans.push_back(ok);
  }

  return ans;
}

TransformBinaryStringUsingSubsequenceSortSolution::
    TransformBinaryStringUsingSubsequenceSortSolution() {
  setMetaInfo({.id = 3998,
               .title = "Transform Binary String Using Subsequence Sort",
               .url = "https://leetcode.com/problems/transform-binary-string-using-subsequence-sort/"});

  registerStrategy(
      {.name = "GreedyPrefixCheck",
       .expected = "Accepted",
       .time_complexity = "O(n * m)",
       .space_complexity = "O(n)",
       .tags = {"greedy", "prefix-sum", "string"}},
      transformStrImpl);
}

std::vector<bool> TransformBinaryStringUsingSubsequenceSortSolution::transformStr(
    std::string s, std::vector<std::string>& strs) {
  return getSolution()(s, strs);
}

}  // namespace problem_3998
}  // namespace leetcode
