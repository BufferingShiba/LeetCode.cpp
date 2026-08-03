// Source file for LeetCode 3823: Reverse Letters Then Special Characters in a String
#include "leetcode/problems/reverse-letters-then-special-characters-in-a-string.h"

namespace leetcode {
namespace problem_3823 {

namespace {

bool isSpecial(char c) {
  switch (c) {
    case '!': case '@': case '#': case '$': case '%':
    case '^': case '&': case '*': case '(': case ')':
      return true;
    default:
      return false;
  }
}

std::string reverseByTypeImpl(std::string s) {
  // Pass 1: reverse the lowercase letters in place.
  int left = 0;
  int right = static_cast<int>(s.size()) - 1;
  while (left < right) {
    if (!islower(static_cast<unsigned char>(s[left]))) {
      ++left;
      continue;
    }
    if (!islower(static_cast<unsigned char>(s[right]))) {
      --right;
      continue;
    }
    std::swap(s[left], s[right]);
    ++left;
    --right;
  }

  // Pass 2: reverse the special characters in place.
  left = 0;
  right = static_cast<int>(s.size()) - 1;
  while (left < right) {
    if (!isSpecial(s[left])) {
      ++left;
      continue;
    }
    if (!isSpecial(s[right])) {
      --right;
      continue;
    }
    std::swap(s[left], s[right]);
    ++left;
    --right;
  }

  return s;
}

}  // namespace

ReverseLettersThenSpecialCharactersInAStringSolution::
    ReverseLettersThenSpecialCharactersInAStringSolution() {
  setMetaInfo({.id = 3823,
               .title =
                   "Reverse Letters Then Special Characters in a String",
               .url =
                   "https://leetcode.com/problems/reverse-letters-then-special-characters-in-a-string/"});
  registerStrategy(
      {.name = "two-pass-swap",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String", "Simulation"}},
      reverseByTypeImpl);
}

std::string ReverseLettersThenSpecialCharactersInAStringSolution::reverseByType(
    std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_3823
}  // namespace leetcode
