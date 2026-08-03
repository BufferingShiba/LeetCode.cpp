#include "leetcode/problems/first-letter-to-appear-twice.h"

namespace leetcode {
namespace problem_2351 {

namespace {

char repeatedCharacterImpl(std::string s) {
  bool seen[26] = {false};
  for (char c : s) {
    int idx = c - 'a';
    if (seen[idx]) {
      return c;
    }
    seen[idx] = true;
  }
  return '\0';  // unreachable: s has at least one repeated letter
}

}  // namespace

FirstLetterToAppearTwiceSolution::FirstLetterToAppearTwiceSolution() {
  setMetaInfo({.id = 2351,
               .title = "First Letter to Appear Twice",
               .url = "https://leetcode.com/problems/first-letter-to-appear-twice/"});
  registerStrategy({.name = "seen-array",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Hash Table", "String", "Counting"}},
                   repeatedCharacterImpl);
}

char FirstLetterToAppearTwiceSolution::repeatedCharacter(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_2351
}  // namespace leetcode
