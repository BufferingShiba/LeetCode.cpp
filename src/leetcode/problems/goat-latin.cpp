#include "leetcode/problems/goat-latin.h"

#include <sstream>
#include <string>
#include <vector>

namespace leetcode::problem_824 {
namespace {

bool isVowel(char c) {
  c = static_cast<char>(std::tolower(c));
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

std::string toGoatLatinImpl(std::string sentence) {
  std::istringstream iss(sentence);
  std::string word;
  std::string result;
  int index = 1;
  bool first_word = true;
  while (iss >> word) {
    if (!first_word) {
      result += ' ';
    }
    first_word = false;

    if (!isVowel(word[0])) {
      word.push_back(word[0]);
      word.erase(word.begin());
    }
    word += "ma";
    word.append(index, 'a');
    result += word;
    ++index;
  }
  return result;
}

}  // namespace

GoatLatinSolution::GoatLatinSolution() {
  setMetaInfo({.id = 824,
               .title = "Goat Latin",
               .url = "https://leetcode.com/problems/goat-latin/"});
  registerStrategy({.name = "Simulation",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"String"}},
                   toGoatLatinImpl);
}

std::string GoatLatinSolution::toGoatLatin(std::string sentence) {
  return getSolution()(std::move(sentence));
}

}  // namespace leetcode::problem_824
