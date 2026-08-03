#include "leetcode/problems/circular-sentence.h"

namespace leetcode {
namespace problem_2490 {

namespace {

bool isCircularSentenceImpl(const std::string& sentence) {
  int n = static_cast<int>(sentence.size());
  for (int i = 0; i < n; ++i) {
    if (sentence[i] == ' ') {
      if (sentence[i - 1] != sentence[i + 1]) {
        return false;
      }
    }
  }
  return sentence.front() == sentence.back();
}

}  // namespace

CircularSentenceSolution::CircularSentenceSolution() {
  setMetaInfo({.id = 2490,
               .title = "Circular Sentence",
               .url = "https://leetcode.com/problems/circular-sentence/"});
  registerStrategy(
      {.name = "single-pass-space-check",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Single Pass"}},
      isCircularSentenceImpl);
}

bool CircularSentenceSolution::isCircularSentence(std::string sentence) {
  return getSolution()(sentence);
}

}  // namespace problem_2490
}  // namespace leetcode
