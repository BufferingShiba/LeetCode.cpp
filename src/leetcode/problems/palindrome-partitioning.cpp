#include "leetcode/problems/palindrome-partitioning.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_131 {

namespace {

void backtrack(const std::string& s, int start,
               const std::vector<std::vector<bool>>& isPal,
               std::vector<std::string>& cur,
               std::vector<std::vector<std::string>>& result) {
  int n = static_cast<int>(s.size());
  if (start == n) {
    result.push_back(cur);
    return;
  }
  for (int end = start; end < n; ++end) {
    if (isPal[start][end]) {
      cur.push_back(s.substr(start, end - start + 1));
      backtrack(s, end + 1, isPal, cur, result);
      cur.pop_back();
    }
  }
}

std::vector<std::vector<std::string>> partitionImpl(std::string s) {
  int n = static_cast<int>(s.size());
  std::vector<std::vector<bool>> isPal(n, std::vector<bool>(n, false));
  for (int i = n - 1; i >= 0; --i) {
    isPal[i][i] = true;
    for (int j = i + 1; j < n; ++j) {
      isPal[i][j] = (s[i] == s[j]) && (j - i == 1 || isPal[i + 1][j - 1]);
    }
  }
  std::vector<std::vector<std::string>> result;
  std::vector<std::string> cur;
  backtrack(s, 0, isPal, cur, result);
  return result;
}

}  // namespace

PalindromePartitioningSolution::PalindromePartitioningSolution() {
  setMetaInfo({.id = 131,
               .title = "Palindrome Partitioning",
               .url = "https://leetcode.com/problems/palindrome-partitioning/"});
  registerStrategy(
      {.name = "backtracking",
       .expected = "Accepted",
       .time_complexity = "O(n * 2^n)",
       .space_complexity = "O(n^2)",
       .tags = {"String", "Dynamic Programming", "Backtracking"}},
      partitionImpl);
}

std::vector<std::vector<std::string>> PalindromePartitioningSolution::partition(
    std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_131
