#include "leetcode/problems/find-the-longest-balanced-substring-of-a-binary-string.h"

#include <algorithm>
#include <string>

namespace leetcode::problem_2609 {

namespace {

int findTheLongestBalancedSubstringImpl(std::string s) {
  const int n = static_cast<int>(s.size());
  int best = 0;
  int i = 0;
  while (i < n) {
    int zeros = 0;
    while (i < n && s[i] == '0') {
      ++zeros;
      ++i;
    }
    int ones = 0;
    while (i < n && s[i] == '1') {
      ++ones;
      ++i;
    }
    best = std::max(best, 2 * std::min(zeros, ones));
  }
  return best;
}

}  // namespace

FindTheLongestBalancedSubstringOfABinaryStringSolution::
    FindTheLongestBalancedSubstringOfABinaryStringSolution() {
  this->setMetaInfo(
      {.id = 2609,
       .title = "Find the Longest Balanced Substring of a Binary String",
       .url = "https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/"});

  this->registerStrategy(
      {.name = "linear-scan-greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String"},
       .notes = "Split into runs of consecutive 0s and 1s; for each adjacent 0-run->1-run pair, answer contributes 2*min(zeros, ones)."},
      findTheLongestBalancedSubstringImpl);
}

int FindTheLongestBalancedSubstringOfABinaryStringSolution::
    findTheLongestBalancedSubstring(std::string s) {
  return this->getSolution()(s);
}

}  // namespace leetcode::problem_2609
