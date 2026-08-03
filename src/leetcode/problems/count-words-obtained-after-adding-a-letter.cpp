// LeetCode problem 2135: Count Words Obtained After Adding a Letter
#include "leetcode/problems/count-words-obtained-after-adding-a-letter.h"

#include <cstddef>
#include <unordered_set>

namespace leetcode {
namespace problem_2135 {
namespace {

int toMask(const std::string& s) {
  int mask = 0;
  for (char c : s) {
    mask |= (1 << (c - 'a'));
  }
  return mask;
}

int wordCountImpl(std::vector<std::string>& startWords,
                  std::vector<std::string>& targetWords) {
  std::unordered_set<int> startMasks;
  startMasks.reserve(startWords.size() * 2);
  for (const auto& w : startWords) {
    startMasks.insert(toMask(w));
  }

  int count = 0;
  for (const auto& t : targetWords) {
    int mask = toMask(t);
    for (int i = 0; i < 26; ++i) {
      if (mask & (1 << i)) {
        int removed = mask ^ (1 << i);
        if (startMasks.count(removed)) {
          ++count;
          break;
        }
      }
    }
  }
  return count;
}

}  // namespace

CountWordsObtainedAfterAddingALetterSolution::
    CountWordsObtainedAfterAddingALetterSolution() {
  this->setMetaInfo({.id = 2135,
                     .title = "Count Words Obtained After Adding a Letter",
                     .url = "https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/"});
  this->registerStrategy(
      {"bitmask-hashset", "Accepted", "O((N+M)*26)", "O(N)",
       {"Array", "Hash Table", "String", "Bit Manipulation"},
       "Convert each word to a 26-bit mask. For each target, try removing one "
       "letter and check if the resulting mask exists in the start set."},
      wordCountImpl);
}

int CountWordsObtainedAfterAddingALetterSolution::wordCount(
    std::vector<std::string>& startWords,
    std::vector<std::string>& targetWords) {
  return getSolution()(startWords, targetWords);
}

}  // namespace problem_2135
}  // namespace leetcode
