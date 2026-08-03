#include "leetcode/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence.h"

#include <sstream>

namespace leetcode::problem_1455 {

namespace {

int isPrefixOfWordImpl(const std::string& sentence,
                       const std::string& searchWord) {
  std::istringstream iss(sentence);
  std::string word;
  int index = 1;
  while (iss >> word) {
    if (word.compare(0, searchWord.size(), searchWord) == 0) {
      return index;
    }
    ++index;
  }
  return -1;
}

}  // namespace

CheckIfAWordOccursAsAPrefixOfAnyWordInASentenceSolution::
    CheckIfAWordOccursAsAPrefixOfAnyWordInASentenceSolution() {
  setMetaInfo({.id = 1455,
               .title = "Check If a Word Occurs As a Prefix of Any Word in a "
                        "Sentence",
               .url = "https://leetcode.com/problems/"
                      "check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-"
                      "sentence/"});
  registerStrategy(
      {.name = "split and prefix",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"String", "String Matching"}},
      &isPrefixOfWordImpl);
}

int CheckIfAWordOccursAsAPrefixOfAnyWordInASentenceSolution::isPrefixOfWord(
    const std::string& sentence, const std::string& searchWord) {
  return getSolution()(sentence, searchWord);
}

}  // namespace leetcode::problem_1455
