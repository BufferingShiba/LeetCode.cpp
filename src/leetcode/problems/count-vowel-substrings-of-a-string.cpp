#include "leetcode/problems/count-vowel-substrings-of-a-string.h"

namespace leetcode {
namespace problem_2062 {

namespace {

bool isVowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }

int countVowelSubstringsImpl(std::string word) {
  int n = static_cast<int>(word.size());
  int res = 0;
  for (int i = 0; i < n; ++i) {
    bool seen[5] = {};
    int count = 0;
    for (int j = i; j < n; ++j) {
      if (!isVowel(word[j])) break;
      int idx = -1;
      switch (word[j]) {
        case 'a': idx = 0; break;
        case 'e': idx = 1; break;
        case 'i': idx = 2; break;
        case 'o': idx = 3; break;
        case 'u': idx = 4; break;
      }
      if (!seen[idx]) { seen[idx] = true; ++count; }
      if (count == 5) ++res;
    }
  }
  return res;
}

}  // namespace

CountVowelSubstringsOfAStringSolution::CountVowelSubstringsOfAStringSolution() {
  setMetaInfo({.id = 2062,
               .title = "Count Vowel Substrings of a String",
               .url = "https://leetcode.com/problems/count-vowel-substrings-of-a-string/"});
  registerStrategy({.name = "bruteForceWindow",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(1)",
                    .tags = {"Hash Table", "String"}},
                   countVowelSubstringsImpl);
}

int CountVowelSubstringsOfAStringSolution::countVowelSubstrings(std::string word) {
  return getSolution()(word);
}

}  // namespace problem_2062
}  // namespace leetcode
