#include "leetcode/problems/word-pattern.h"

#include <sstream>
#include <string>
#include <unordered_map>

namespace leetcode::problem_290 {

namespace {

bool wordPatternImpl(const std::string& pattern, const std::string& s) {
  std::istringstream iss(s);
  std::string word;
  std::unordered_map<char, std::string> charToWord;
  std::unordered_map<std::string, char> wordToChar;

  int i = 0;
  while (iss >> word) {
    if (i >= static_cast<int>(pattern.size())) {
      return false;  // more words than pattern chars
    }
    char c = pattern[i];

    auto it1 = charToWord.find(c);
    auto it2 = wordToChar.find(word);
    if (it1 != charToWord.end() && it1->second != word) {
      return false;
    }
    if (it2 != wordToChar.end() && it2->second != c) {
      return false;
    }
    if (it1 == charToWord.end() && it2 == wordToChar.end()) {
      charToWord[c] = word;
      wordToChar[word] = c;
    }
    ++i;
  }

  return i == static_cast<int>(pattern.size());
}

}  // namespace

WordPatternSolution::WordPatternSolution() {
  setMetaInfo({.id = 290,
               .title = "Word Pattern",
               .url = "https://leetcode.com/problems/word-pattern/"});
  registerStrategy(
      {.name = "hashmap bijection",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "String"}},
      wordPatternImpl);
}

bool WordPatternSolution::wordPattern(std::string pattern, std::string s) {
  return getSolution()(std::move(pattern), std::move(s));
}

}  // namespace leetcode::problem_290
