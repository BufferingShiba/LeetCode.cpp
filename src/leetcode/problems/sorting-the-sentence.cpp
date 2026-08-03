#include "leetcode/problems/sorting-the-sentence.h"

#include <sstream>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1859 {

static std::string sortSentenceImpl(std::string s) {
  // Count words first to allocate exact size.
  int wordCount = 0;
  for (char ch : s) {
    if (ch == ' ') ++wordCount;
  }
  ++wordCount;  // words = spaces + 1

  std::vector<std::string> words(wordCount);
  std::istringstream iss(s);
  std::string token;
  while (iss >> token) {
    int pos = token.back() - '0';       // 1-indexed position
    token.pop_back();                   // remove the digit
    words[pos - 1] = std::move(token);
  }

  std::string result;
  for (int i = 0; i < wordCount; ++i) {
    if (i > 0) result += ' ';
    result += words[i];
  }
  return result;
}

SortingTheSentenceSolution::SortingTheSentenceSolution() {
  setMetaInfo({.id = 1859,
               .title = "Sorting the Sentence",
               .url = "https://leetcode.com/problems/sorting-the-sentence/"});

  registerStrategy(
      {.name = "bucket-sort",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"String", "Sorting"}},
      sortSentenceImpl);
}

std::string SortingTheSentenceSolution::sortSentence(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_1859
}  // namespace leetcode
