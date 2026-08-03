#include "leetcode/problems/truncate-sentence.h"

namespace leetcode::problem_1816 {

namespace {

std::string truncate_by_scanning(std::string s, int k) {
  int word_count = 0;
  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    if (s[i] == ' ') {
      ++word_count;
      if (word_count == k) {
        return s.substr(0, i);
      }
    }
  }
  return s;
}

}  // namespace

TruncateSentenceSolution::TruncateSentenceSolution() {
  setMetaInfo({.id = 1816,
               .title = "Truncate Sentence",
               .url = "https://leetcode.com/problems/truncate-sentence/"});

  registerStrategy({.name = "linear_scan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"String", "Array"}},
                   truncate_by_scanning);
}

std::string TruncateSentenceSolution::truncateSentence(std::string s, int k) {
  return getSolution()(std::move(s), k);
}

}  // namespace leetcode::problem_1816
