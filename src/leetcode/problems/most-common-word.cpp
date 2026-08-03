#include "leetcode/problems/most-common-word.h"

#include <cctype>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace leetcode::problem_819 {

namespace {

std::string mostCommonWordImpl(std::string paragraph, std::vector<std::string>& banned) {
  std::unordered_set<std::string> bannedSet(banned.begin(), banned.end());
  std::unordered_map<std::string, int> freq;

  std::string word;
  int bestCount = 0;
  std::string bestWord;

  auto flush = [&]() {
    if (!word.empty()) {
      if (bannedSet.find(word) == bannedSet.end()) {
        int count = ++freq[word];
        if (count > bestCount) {
          bestCount = count;
          bestWord = word;
        }
      }
      word.clear();
    }
  };

  for (char c : paragraph) {
    if (std::isalpha(static_cast<unsigned char>(c))) {
      word.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(c))));
    } else {
      flush();
    }
  }
  flush();

  return bestWord;
}

}  // namespace

std::string MostCommonWordSolution::mostCommonWord(std::string paragraph,
                                                   std::vector<std::string>& banned) {
  return getSolution()(std::move(paragraph), banned);
}

MostCommonWordSolution::MostCommonWordSolution() {
  setMetaInfo({.id = 819,
               .title = "Most Common Word",
               .url = "https://leetcode.com/problems/most-common-word/"});
  registerStrategy({.name = "hash-map-counting",
                    .expected = "Accepted",
                    .time_complexity = "O(n + m)",
                    .space_complexity = "O(n + m)",
                    .tags = {"Array", "Hash Table", "String", "Counting"}},
                   mostCommonWordImpl);
}

}  // namespace leetcode::problem_819
