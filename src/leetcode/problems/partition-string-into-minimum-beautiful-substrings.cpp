#include "leetcode/problems/partition-string-into-minimum-beautiful-substrings.h"

#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

namespace leetcode::problem_2767 {

namespace {

std::unordered_set<std::string> generatePowerOfFiveStrings(int maxLen) {
  std::unordered_set<std::string> result;
  long long val = 1;
  while (true) {
    std::string bin;
    long long tmp = val;
    while (tmp > 0) {
      bin.push_back((tmp & 1) ? '1' : '0');
      tmp >>= 1;
    }
    std::reverse(bin.begin(), bin.end());
    if (static_cast<int>(bin.length()) > maxLen) break;
    result.insert(bin);
    val *= 5;
  }
  return result;
}

int minimumBeautifulSubstringsImpl(const std::string& s) {
  const int n = static_cast<int>(s.size());
  auto powerOfFive = generatePowerOfFiveStrings(n);

  const int INF = n + 1;
  std::vector<int> dp(n + 1, INF);
  dp[0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (s[j] == '0') continue;  // leading zero not allowed
      std::string sub = s.substr(j, i - j);
      if (powerOfFive.count(sub)) {
        dp[i] = std::min(dp[i], dp[j] + 1);
      }
    }
  }

  return dp[n] == INF ? -1 : dp[n];
}

}  // namespace

PartitionStringIntoMinimumBeautifulSubstringsSolution::PartitionStringIntoMinimumBeautifulSubstringsSolution() {
  setMetaInfo({.id = 2767,
               .title = "Partition String Into Minimum Beautiful Substrings",
               .url = "https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/"});
  registerStrategy(
      {.name = "DP",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "String", "Dynamic Programming", "Backtracking"}},
      minimumBeautifulSubstringsImpl);
}

int PartitionStringIntoMinimumBeautifulSubstringsSolution::minimumBeautifulSubstrings(std::string s) {
  return getSolution()(s);
}

}  // namespace leetcode::problem_2767
