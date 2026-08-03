#include "leetcode/problems/extra-characters-in-a-string.h"

#include <string>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_2707 {

namespace {

int minExtraCharImpl(std::string s, std::vector<std::string>& dictionary) {
  std::unordered_set<std::string> dict(dictionary.begin(), dictionary.end());
  int n = static_cast<int>(s.size());
  std::vector<int> dp(n + 1, 0);

  for (int i = 1; i <= n; ++i) {
    // treat s[i-1] as an extra character
    dp[i] = dp[i - 1] + 1;

    // try all substrings ending at i-1
    for (int j = 0; j < i; ++j) {
      std::string sub = s.substr(j, i - j);
      if (dict.count(sub)) {
        dp[i] = std::min(dp[i], dp[j]);
      }
    }
  }

  return dp[n];
}

}  // namespace

ExtraCharactersInAStringSolution::ExtraCharactersInAStringSolution() {
  setMetaInfo({.id = 2707,
               .title = "Extra Characters in a String",
               .url = "https://leetcode.com/problems/extra-characters-in-a-string/"});
  registerStrategy(
      {.name = "DP + HashSet",
       .expected = "Accepted",
       .time_complexity = "O(n^2 * L)",
       .space_complexity = "O(m + n)",
       .tags = {"Array", "Hash Table", "String", "Dynamic Programming"}},
      minExtraCharImpl);
  setDefaultStrategy();
}

int ExtraCharactersInAStringSolution::minExtraChar(
    std::string s, std::vector<std::string>& dictionary) {
  return getSolution()(s, dictionary);
}

}  // namespace problem_2707
}  // namespace leetcode
