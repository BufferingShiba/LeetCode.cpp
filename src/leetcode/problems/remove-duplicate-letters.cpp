#include "leetcode/problems/remove-duplicate-letters.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode::problem_316 {

namespace {

std::string removeDuplicateLettersImpl(std::string s) {
  constexpr int kAlphabet = 26;

  int last[kAlphabet] = {0};
  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    last[s[i] - 'a'] = i;
  }

  bool visited[kAlphabet] = {false};
  std::string result;
  result.reserve(kAlphabet);

  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    char c = s[i];
    int idx = c - 'a';

    if (visited[idx]) continue;

    while (!result.empty() && result.back() > c && last[result.back() - 'a'] > i) {
      visited[result.back() - 'a'] = false;
      result.pop_back();
    }

    result.push_back(c);
    visited[idx] = true;
  }

  return result;
}

}  // namespace

RemoveDuplicateLettersSolution::RemoveDuplicateLettersSolution() {
  setMetaInfo({.id = 316,
               .title = "Remove Duplicate Letters",
               .url = "https://leetcode.com/problems/remove-duplicate-letters/"});
  registerStrategy(
      {.name = "Monotonic Stack",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Stack", "Greedy", "Monotonic Stack"}},
      removeDuplicateLettersImpl);
}

std::string RemoveDuplicateLettersSolution::removeDuplicateLetters(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_316
