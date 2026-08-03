#include "leetcode/problems/maximum-number-of-words-you-can-type.h"

#include <cstddef>
#include <string>

namespace leetcode::problem_1935 {

namespace {

int canBeTypedWordsImpl(const std::string& text, const std::string& brokenLetters) {
  bool broken[26] = {false};
  for (char c : brokenLetters) {
    broken[c - 'a'] = true;
  }

  int words = 0;
  bool currentBroken = false;
  for (std::size_t i = 0; i < text.size(); ++i) {
    if (text[i] == ' ') {
      if (!currentBroken) {
        ++words;
      }
      currentBroken = false;
    } else if (broken[text[i] - 'a']) {
      currentBroken = true;
    }
  }
  if (!currentBroken) {
    ++words;
  }
  return words;
}

}  // namespace

MaximumNumberOfWordsYouCanTypeSolution::MaximumNumberOfWordsYouCanTypeSolution() {
  setMetaInfo({.id = 1935,
               .title = "Maximum Number of Words You Can Type",
               .url = "https://leetcode.com/problems/maximum-number-of-words-you-can-type/"});
  registerStrategy({.name = "HashSet broken letters scan",
                    .expected = "Accepted",
                    .time_complexity = "O(n + m)",
                    .space_complexity = "O(26)",
                    .tags = {"Hash Table", "String"}},
                   canBeTypedWordsImpl);
}

int MaximumNumberOfWordsYouCanTypeSolution::canBeTypedWords(std::string text,
                                                            std::string brokenLetters) {
  return getSolution()(std::move(text), std::move(brokenLetters));
}

}  // namespace leetcode::problem_1935
