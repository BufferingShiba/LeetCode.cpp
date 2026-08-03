#include "leetcode/problems/find-valid-pair-of-adjacent-digits-in-string.h"

namespace leetcode::problem_3438 {

namespace {

std::string findValidPairImpl(std::string s) {
  int count[10] = {0};
  for (char c : s) {
    ++count[c - '0'];
  }
  const int n = static_cast<int>(s.size());
  for (int i = 0; i + 1 < n; ++i) {
    int a = s[i] - '0';
    int b = s[i + 1] - '0';
    if (a != b && count[a] == a && count[b] == b) {
      return s.substr(i, 2);
    }
  }
  return "";
}

}  // namespace

FindValidPairOfAdjacentDigitsInStringSolution::
    FindValidPairOfAdjacentDigitsInStringSolution() {
  setMetaInfo({.id = 3438,
               .title = "Find Valid Pair of Adjacent Digits in String",
               .url = "https://leetcode.com/problems/find-valid-pair-of-adjacent-digits-in-string/"});
  registerStrategy(
      {.name = "counting-and-scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String", "Counting"}},
      findValidPairImpl);
}

std::string FindValidPairOfAdjacentDigitsInStringSolution::findValidPair(
    std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_3438
