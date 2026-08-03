#include "leetcode/problems/sort-vowels-in-a-string.h"

#include <algorithm>

namespace leetcode {
namespace problem_2785 {

static bool isVowel(char c) {
  switch (c) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
    case 'A': case 'E': case 'I': case 'O': case 'U':
      return true;
    default:
      return false;
  }
}

static string solution1(string s) {
  std::vector<char> vowels;
  for (char c : s) {
    if (isVowel(c)) {
      vowels.push_back(c);
    }
  }
  std::sort(vowels.begin(), vowels.end());
  size_t idx = 0;
  for (size_t i = 0; i < s.size(); ++i) {
    if (isVowel(s[i])) {
      s[i] = vowels[idx++];
    }
  }
  return s;
}

SortVowelsInAStringSolution::SortVowelsInAStringSolution() {
  setMetaInfo({
      .id = 2785,
      .title = "Sort Vowels in a String",
      .url = "https://leetcode.com/problems/sort-vowels-in-a-string"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

string SortVowelsInAStringSolution::sortVowels(string s) {
  return getSolution()(s);
}

}  // namespace problem_2785
}  // namespace leetcode
