#include "leetcode/problems/longest-common-prefix.h"

#include <algorithm>

namespace leetcode {
namespace problem_14 {

static string solution1(vector<string>& strs) {
  if (strs.empty()) return string();
  string prefix;
  const size_t firstLen = strs[0].size();
  for (size_t i = 0; i < firstLen; ++i) {
    char c = strs[0][i];
    for (size_t j = 1; j < strs.size(); ++j) {
      if (i >= strs[j].size() || strs[j][i] != c) {
        return prefix;
      }
    }
    prefix.push_back(c);
  }
  return prefix;
}

LongestCommonPrefixSolution::LongestCommonPrefixSolution() {
  setMetaInfo({
      .id = 14,
      .title = "Longest Common Prefix",
      .url = "https://leetcode.com/problems/longest-common-prefix"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

string LongestCommonPrefixSolution::longestCommonPrefix(vector<string>& strs) {
  return getSolution()(strs);
}

}  // namespace problem_14
}  // namespace leetcode
