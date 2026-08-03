#include "leetcode/problems/occurrences-after-bigram.h"

#include <sstream>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1078 {
namespace {

std::vector<std::string> findOcurrencesImpl(std::string text, std::string first, std::string second) {
  std::vector<std::string> words;
  std::istringstream iss(text);
  std::string word;
  while (iss >> word) {
    words.push_back(word);
  }

  std::vector<std::string> result;
  for (std::size_t i = 0; i + 2 < words.size(); ++i) {
    if (words[i] == first && words[i + 1] == second) {
      result.push_back(words[i + 2]);
    }
  }
  return result;
}

}  // namespace

OccurrencesAfterBigramSolution::OccurrencesAfterBigramSolution() {
  setMetaInfo({.id = 1078, .title = "Occurrences After Bigram", .url = "https://leetcode.com/problems/occurrences-after-bigram/"});
  registerStrategy(
      {"LinearScan", "Accepted", "O(n)", "O(n)", {"String"}},
      findOcurrencesImpl);
}

std::vector<std::string> OccurrencesAfterBigramSolution::findOcurrences(
    std::string text, std::string first, std::string second) {
  return getSolution()(std::move(text), std::move(first), std::move(second));
}

}  // namespace problem_1078
}  // namespace leetcode
