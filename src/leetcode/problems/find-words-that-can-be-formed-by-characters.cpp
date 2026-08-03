#include <array>
#include <string>
#include <vector>

#include "leetcode/problems/find-words-that-can-be-formed-by-characters.h"

namespace leetcode::problem_1160 {

namespace {

int countCharactersImpl(std::vector<std::string>& words, std::string chars) {
  std::array<int, 26> base{};
  for (char c : chars) {
    ++base[c - 'a'];
  }

  int total = 0;
  for (const std::string& word : words) {
    std::array<int, 26> need{};
    for (char c : word) {
      ++need[c - 'a'];
    }
    bool good = true;
    for (int i = 0; i < 26; ++i) {
      if (need[i] > base[i]) {
        good = false;
        break;
      }
    }
    if (good) {
      total += static_cast<int>(word.size());
    }
  }
  return total;
}

}  // namespace

FindWordsThatCanBeFormedByCharactersSolution::
    FindWordsThatCanBeFormedByCharactersSolution() {
  setMetaInfo({.id = 1160,
               .title = "Find Words That Can Be Formed by Characters",
               .url = "https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/"});

  registerStrategy({.name = "counting-array",
                    .expected = "Accepted",
                    .time_complexity = "O(L)",
                    .space_complexity = "O(26)",
                    .tags = {"Array", "Hash Table", "String", "Counting"}}
                   ,
                   countCharactersImpl);
}

int FindWordsThatCanBeFormedByCharactersSolution::countCharacters(
    std::vector<std::string>& words, std::string chars) {
  return getSolution()(words, chars);
}

}  // namespace leetcode::problem_1160
