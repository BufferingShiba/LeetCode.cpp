#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

#include "leetcode/problems/longest-word-in-dictionary.h"

namespace leetcode::problem_720 {

namespace {

std::string longestWordImpl(std::vector<std::string>& words) {
  std::sort(words.begin(), words.end());

  std::unordered_set<std::string> built;
  std::string answer;

  for (const auto& word : words) {
    if (word.size() == 1 || built.count(word.substr(0, word.size() - 1))) {
      built.insert(word);
      if (word.size() > answer.size()) {
        answer = word;
      }
    }
  }

  return answer;
}

}  // namespace

LongestWordInDictionarySolution::LongestWordInDictionarySolution() {
  setMetaInfo({.id = 720,
               .title = "Longest Word in Dictionary",
               .url = "https://leetcode.com/problems/longest-word-in-dictionary/"});

  registerStrategy({.name = "hashset",
                    .expected = "Accepted",
                    .time_complexity = "O(N*L*log N)",
                    .space_complexity = "O(N*L)",
                    .tags = {"Hash Table", "String", "Sorting"}},
                   longestWordImpl);
}

std::string LongestWordInDictionarySolution::longestWord(
    std::vector<std::string>& words) {
  return getSolution()(words);
}

}  // namespace leetcode::problem_720
