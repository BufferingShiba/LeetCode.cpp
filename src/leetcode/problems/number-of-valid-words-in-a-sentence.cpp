#include "leetcode/problems/number-of-valid-words-in-a-sentence.h"

#include <cctype>
#include <sstream>

namespace leetcode {
namespace problem_2047 {

namespace {

bool isPunctuation(char c) {
  return c == '!' || c == '.' || c == ',';
}

bool isValidWord(const std::string& token) {
  if (token.empty()) return false;

  int hyphenCount = 0;
  int punctuationCount = 0;

  for (std::size_t i = 0; i < token.size(); ++i) {
    char c = token[i];
    if (std::isdigit(static_cast<unsigned char>(c))) {
      return false;
    }
    if (c == '-') {
      ++hyphenCount;
      if (hyphenCount > 1) return false;
      // Hyphen must be surrounded by lowercase letters.
      if (i == 0 || i + 1 >= token.size()) return false;
      if (!std::islower(static_cast<unsigned char>(token[i - 1])) ||
          !std::islower(static_cast<unsigned char>(token[i + 1]))) {
        return false;
      }
    } else if (isPunctuation(c)) {
      ++punctuationCount;
      if (punctuationCount > 1) return false;
      // Punctuation must be at the end.
      if (i + 1 != token.size()) return false;
    } else if (!std::islower(static_cast<unsigned char>(c))) {
      // Uppercase letters are not allowed (only lowercase by constraint).
      return false;
    }
  }

  return true;
}

int countValidWordsImpl(std::string sentence) {
  std::istringstream iss(sentence);
  std::string token;
  int count = 0;
  while (iss >> token) {
    if (isValidWord(token)) {
      ++count;
    }
  }
  return count;
}

}  // namespace

NumberOfValidWordsInASentenceSolution::NumberOfValidWordsInASentenceSolution() {
  setMetaInfo(
      {.id = 2047,
       .title = "Number of Valid Words in a Sentence",
       .url =
           "https://leetcode.com/problems/number-of-valid-words-in-a-sentence/"});

  registerStrategy(
      {.name = "single-pass",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"String"}},
      countValidWordsImpl);
}

int NumberOfValidWordsInASentenceSolution::countValidWords(std::string sentence) {
  return getSolution()(std::move(sentence));
}

}  // namespace problem_2047
}  // namespace leetcode
