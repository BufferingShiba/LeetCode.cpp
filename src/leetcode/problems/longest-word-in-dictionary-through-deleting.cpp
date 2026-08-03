#include "leetcode/problems/longest-word-in-dictionary-through-deleting.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_524 {
namespace {

// Checks whether `word` is a subsequence of `s` using the greedy two-pointer
// technique. Matching each character of `word` at the earliest possible
// position in `s` is provably optimal for subsequence existence.
bool isSubsequence(const std::string& s, const std::string& word) {
  int i = 0;
  for (char c : word) {
    while (i < static_cast<int>(s.size()) && s[i] != c) {
      ++i;
    }
    if (i == static_cast<int>(s.size())) {
      return false;
    }
    ++i;
  }
  return true;
}

}  // namespace

LongestWordInDictionaryThroughDeletingSolution::
    LongestWordInDictionaryThroughDeletingSolution() {
  setMetaInfo({.id = 524,
               .title = "Longest Word in Dictionary through Deleting",
               .url = "https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/"});

  registerStrategy(
      {.name = "greedy-subsequence",
       .expected = "Accepted",
       .time_complexity = "O(s_len * dict_len)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "String", "Sorting"}},
      [](std::string s, std::vector<std::string>& dictionary) {
        std::string best;
        for (const std::string& word : dictionary) {
          if (isSubsequence(s, word)) {
            if (word.size() > best.size() ||
                (word.size() == best.size() && word < best)) {
              best = word;
            }
          }
        }
        return best;
      });
}

std::string LongestWordInDictionaryThroughDeletingSolution::findLongestWord(
    std::string s, std::vector<std::string>& dictionary) {
  return getSolution()(std::move(s), dictionary);
}

}  // namespace problem_524
}  // namespace leetcode
