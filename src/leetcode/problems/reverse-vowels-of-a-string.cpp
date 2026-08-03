#include "leetcode/problems/reverse-vowels-of-a-string.h"

namespace leetcode::problem_345 {

namespace {

bool isVowel(char c) {
  switch (c) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
    case 'A': case 'E': case 'I': case 'O': case 'U':
      return true;
    default:
      return false;
  }
}

std::string reverseVowelsImpl(std::string s) {
  int left = 0;
  int right = static_cast<int>(s.size()) - 1;
  while (left < right) {
    while (left < right && !isVowel(s[left])) {
      ++left;
    }
    while (left < right && !isVowel(s[right])) {
      --right;
    }
    if (left < right) {
      std::swap(s[left], s[right]);
      ++left;
      --right;
    }
  }
  return s;
}

}  // namespace

ReverseVowelsOfAStringSolution::ReverseVowelsOfAStringSolution() {
  setMetaInfo({345, "Reverse Vowels of a String", "https://leetcode.com/problems/reverse-vowels-of-a-string/"});
  registerStrategy(
      {"TwoPointers", "Accepted", "O(n)", "O(1)",
       {"Two Pointers", "String"}},
      reverseVowelsImpl);
}

std::string ReverseVowelsOfAStringSolution::reverseVowels(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_345
