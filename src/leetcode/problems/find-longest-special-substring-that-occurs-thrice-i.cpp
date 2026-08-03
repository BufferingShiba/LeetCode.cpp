#include "leetcode/problems/find-longest-special-substring-that-occurs-thrice-i.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2981 {

namespace {

int maximumLengthImpl(std::string s) {
  const int n = static_cast<int>(s.size());

  // 按字符收集所有 run 长度
  std::vector<std::vector<int>> runs(26);

  int i = 0;
  while (i < n) {
    int j = i;
    while (j < n && s[j] == s[i]) {
      ++j;
    }
    int len = j - i;
    runs[s[i] - 'a'].push_back(len);
    i = j;
  }

  int best = -1;

  for (int c = 0; c < 26; ++c) {
    const auto& lens = runs[c];
    if (lens.empty()) continue;

    int max_run = *std::max_element(lens.begin(), lens.end());

    // 从大到小尝试 L
    for (int L = max_run; L >= 1; --L) {
      int count = 0;
      for (int len : lens) {
        if (len >= L) {
          count += len - L + 1;
          if (count >= 3) break;
        }
      }
      if (count >= 3) {
        if (L > best) best = L;
        break;
      }
    }
  }

  return best;
}

}  // namespace

FindLongestSpecialSubstringThatOccursThriceISolution::
    FindLongestSpecialSubstringThatOccursThriceISolution() {
  setMetaInfo({.id = 2981,
               .title = "Find Longest Special Substring That Occurs Thrice I",
               .url = "https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/"});
  registerStrategy(
      {.name = "Brute Force by Runs",
       .expected = "Accepted",
       .time_complexity = "O(26 * n^2)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "String", "Counting"}},
      maximumLengthImpl);
  setDefaultStrategy();
}

int FindLongestSpecialSubstringThatOccursThriceISolution::maximumLength(
    std::string s) {
  return getSolution()(s);
}

}  // namespace problem_2981
}  // namespace leetcode
