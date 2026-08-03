#include "leetcode/problems/append-characters-to-string-to-make-subsequence.h"

namespace leetcode::problem_2486 {

static int appendCharactersImpl(std::string s, std::string t) {
  int j = 0;
  for (char c : s) {
    if (j < static_cast<int>(t.size()) && c == t[j]) {
      ++j;
    }
  }
  return static_cast<int>(t.size()) - j;
}

AppendCharactersToStringToMakeSubsequenceSolution::
    AppendCharactersToStringToMakeSubsequenceSolution() {
  setMetaInfo({.id = 2486,
               .title = "Append Characters to String to Make Subsequence",
               .url = "https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/"});
  registerStrategy(
      {.name = "Greedy Two Pointers",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String", "Greedy"}},
      appendCharactersImpl);
  setDefaultStrategy();
}

int AppendCharactersToStringToMakeSubsequenceSolution::appendCharacters(
    std::string s, std::string t) {
  return getSolution()(std::move(s), std::move(t));
}

}  // namespace leetcode::problem_2486
