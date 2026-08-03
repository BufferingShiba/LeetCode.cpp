#include "leetcode/problems/maximum-number-of-words-found-in-sentences.h"

namespace leetcode::problem_2114 {

namespace {
// Count words in a sentence as (number of spaces + 1), because each sentence
// starts with a word and words are separated by exactly one space with no
// leading/trailing spaces.
int mostWordsFoundImpl(std::vector<std::string>& sentences) {
  int maxWords = 0;
  for (const std::string& sentence : sentences) {
    int spaces = 0;
    for (char c : sentence) {
      if (c == ' ') {
        ++spaces;
      }
    }
    int words = spaces + 1;
    if (words > maxWords) {
      maxWords = words;
    }
  }
  return maxWords;
}
}  // namespace

MaximumNumberOfWordsFoundInSentencesSolution::
    MaximumNumberOfWordsFoundInSentencesSolution() {
  setMetaInfo({.id = 2114,
               .title = "Maximum Number of Words Found in Sentences",
               .url = "https://leetcode.com/problems/maximum-number-of-words-"
                       "found-in-sentences/"});
  registerStrategy(
      {.name = "CountSpaces", .expected = "Accepted",
       .time_complexity = "O(n*m)", .space_complexity = "O(1)",
       .tags = {"Array", "String"},
       .notes = "Words in a sentence = spaces + 1"},
      mostWordsFoundImpl);
}

int MaximumNumberOfWordsFoundInSentencesSolution::mostWordsFound(
    std::vector<std::string>& sentences) {
  return getSolution()(sentences);
}

}  // namespace leetcode::problem_2114
