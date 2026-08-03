#include "leetcode/problems/reverse-words-in-a-string-iii.h"

#include <algorithm>
#include <string>

namespace leetcode::problem_557 {

namespace {

std::string reverseWordsImpl(std::string s) {
  int n = static_cast<int>(s.size());
  int start = 0;
  for (int end = 0; end <= n; ++end) {
    if (end == n || s[end] == ' ') {
      std::reverse(s.begin() + start, s.begin() + end);
      start = end + 1;
    }
  }
  return s;
}

}  // namespace

ReverseWordsInAStringIiiSolution::ReverseWordsInAStringIiiSolution() {
  setMetaInfo({.id = 557,
               .title = "Reverse Words in a String III",
               .url = "https://leetcode.com/problems/reverse-words-in-a-string-iii/"});
  registerStrategy(
      {.name = "two_pointers",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String"}},
      reverseWordsImpl);
}

std::string ReverseWordsInAStringIiiSolution::reverseWords(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_557
