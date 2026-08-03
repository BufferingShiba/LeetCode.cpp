#include <string>

#include "leetcode/problems/split-a-string-in-balanced-strings.h"

namespace leetcode::problem_1221 {

namespace {

int balancedStringSplitImpl(const std::string& s) {
  int balance = 0;
  int count = 0;
  for (char c : s) {
    if (c == 'R') {
      ++balance;
    } else {
      --balance;
    }
    if (balance == 0) {
      ++count;
    }
  }
  return count;
}

}  // namespace

SplitAStringInBalancedStringsSolution::SplitAStringInBalancedStringsSolution() {
  setMetaInfo({.id = 1221,
               .title = "Split a String in Balanced Strings",
               .url = "https://leetcode.com/problems/split-a-string-in-balanced-strings/"});
  registerStrategy(
      {.name = "GreedyBalanceCount",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Greedy", "Counting"}},
      balancedStringSplitImpl);
}

int SplitAStringInBalancedStringsSolution::balancedStringSplit(const std::string& s) {
  return getSolution()(s);
}

}  // namespace leetcode::problem_1221
