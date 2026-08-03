#include "leetcode/problems/valid-word.h"

#include <cctype>

namespace leetcode::problem_3136 {

namespace {

bool isValidImpl(std::string word) {
  if (word.size() < 3) {
    return false;
  }
  bool hasVowel = false;
  bool hasConsonant = false;
  for (char c : word) {
    if (std::isupper(c) || std::islower(c)) {
      c = static_cast<char>(std::tolower(c));
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        hasVowel = true;
      } else {
        hasConsonant = true;
      }
    } else if (std::isdigit(c)) {
      continue;
    } else {
      return false;
    }
  }
  return hasVowel && hasConsonant;
}

}  // namespace

ValidWordSolution::ValidWordSolution() {
  setMetaInfo({.id = 3136,
               .title = "Valid Word",
               .url = "https://leetcode.com/problems/valid-word/"});
  registerStrategy(
      {.name = "LinearScan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String"}},
      isValidImpl);
}

bool ValidWordSolution::isValid(std::string word) {
  return getSolution()(word);
}

}  // namespace leetcode::problem_3136
