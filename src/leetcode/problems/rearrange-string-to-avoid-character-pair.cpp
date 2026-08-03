#include "leetcode/problems/rearrange-string-to-avoid-character-pair.h"

#include <string>

namespace leetcode::problem_3992 {

namespace {

std::string rearrangeStringImpl(std::string s, char x, char y) {
  int count[26] = {0};
  for (char c : s) {
    ++count[c - 'a'];
  }

  std::string result;
  result.reserve(s.size());

  // 1) all occurrences of y
  result.append(count[y - 'a'], y);

  // 2) all other characters except x and y
  for (int i = 0; i < 26; ++i) {
    char c = static_cast<char>('a' + i);
    if (c == x || c == y) continue;
    result.append(count[i], c);
  }

  // 3) all occurrences of x
  result.append(count[x - 'a'], x);

  return result;
}

}  // namespace

RearrangeStringToAvoidCharacterPairSolution::RearrangeStringToAvoidCharacterPairSolution() {
  setMetaInfo({.id = 3992,
               .title = "Rearrange String to Avoid Character Pair",
               .url = "https://leetcode.com/problems/rearrange-string-to-avoid-character-pair/"});

  registerStrategy(
      {.name = "Counting",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"string", "counting", "greedy"}},
      rearrangeStringImpl);

  setDefaultStrategy();
}

std::string RearrangeStringToAvoidCharacterPairSolution::rearrangeString(std::string s, char x,
                                                                         char y) {
  return getSolution()(std::move(s), x, y);
}

}  // namespace leetcode::problem_3992
