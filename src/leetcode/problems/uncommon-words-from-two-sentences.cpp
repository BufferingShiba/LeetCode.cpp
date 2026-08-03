#include "leetcode/problems/uncommon-words-from-two-sentences.h"

#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_884 {

namespace {

std::vector<std::string> uncommonFromSentencesImpl(std::string s1,
                                                   std::string s2) {
  std::unordered_map<std::string, int> count;
  std::string token;
  std::istringstream iss(s1 + " " + s2);
  while (iss >> token) {
    ++count[token];
  }

  std::vector<std::string> result;
  for (const auto& [word, cnt] : count) {
    if (cnt == 1) {
      result.push_back(word);
    }
  }
  return result;
}

}  // namespace

UncommonWordsFromTwoSentencesSolution::UncommonWordsFromTwoSentencesSolution() {
  setMetaInfo({.id = 884,
               .title = "Uncommon Words from Two Sentences",
               .url = "https://leetcode.com/problems/uncommon-words-from-two-sentences/"});
  registerStrategy({.name = "HashCounting",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Hash Table", "String", "Counting"}},
                   uncommonFromSentencesImpl);
}

std::vector<std::string> UncommonWordsFromTwoSentencesSolution::uncommonFromSentences(
    std::string s1, std::string s2) {
  return getSolution()(s1, s2);
}

}  // namespace problem_884
}  // namespace leetcode
