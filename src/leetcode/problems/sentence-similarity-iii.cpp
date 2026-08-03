#include "leetcode/problems/sentence-similarity-iii.h"

#include <sstream>
#include <vector>

namespace leetcode {
namespace problem_1813 {
namespace {

std::vector<std::string> SplitWords(const std::string& sentence) {
  std::vector<std::string> words;
  std::istringstream iss(sentence);
  std::string word;
  while (iss >> word) {
    words.push_back(word);
  }
  return words;
}

bool areSentencesSimilarImpl(const std::string& sentence1,
                             const std::string& sentence2) {
  std::vector<std::string> a = SplitWords(sentence1);
  std::vector<std::string> b = SplitWords(sentence2);
  if (a.size() > b.size()) {
    a.swap(b);
  }

  int prefix = 0;
  while (prefix < static_cast<int>(a.size()) &&
         a[prefix] == b[prefix]) {
    ++prefix;
  }
  if (prefix == static_cast<int>(a.size())) {
    return true;
  }

  int suffix = 0;
  while (suffix < static_cast<int>(a.size()) - prefix &&
         a[a.size() - 1 - suffix] == b[b.size() - 1 - suffix]) {
    ++suffix;
  }
  return prefix + suffix >= static_cast<int>(a.size());
}

}  // namespace

SentenceSimilarityIiiSolution::SentenceSimilarityIiiSolution() {
  setMetaInfo({.id = 1813,
               .title = "Sentence Similarity III",
               .url = "https://leetcode.com/problems/sentence-similarity-iii/"});
  registerStrategy({.name = "two-pointers",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Two Pointers", "String"}},
                   areSentencesSimilarImpl);
}

bool SentenceSimilarityIiiSolution::areSentencesSimilar(
    std::string sentence1, std::string sentence2) {
  return getSolution()(sentence1, sentence2);
}

}  // namespace problem_1813
}  // namespace leetcode
