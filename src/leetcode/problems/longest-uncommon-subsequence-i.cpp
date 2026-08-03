#include "leetcode/problems/longest-uncommon-subsequence-i.h"

#include <algorithm>
#include <string>

namespace leetcode::problem_521 {

namespace {

int findLUSlengthImpl(std::string a, std::string b) {
  if (a == b) {
    return -1;
  }
  return static_cast<int>(std::max(a.size(), b.size()));
}

}  // namespace

LongestUncommonSubsequenceISolution::LongestUncommonSubsequenceISolution() {
  this->setMetaInfo({.id = 521,
                     .title = "Longest Uncommon Subsequence I",
                     .url = "https://leetcode.com/problems/longest-uncommon-subsequence-i/"});
  this->registerStrategy(
      {.name = "compare",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"String"}},
      findLUSlengthImpl);
}

int LongestUncommonSubsequenceISolution::findLUSlength(std::string a, std::string b) {
  return this->getSolution()(std::move(a), std::move(b));
}

}  // namespace leetcode::problem_521
