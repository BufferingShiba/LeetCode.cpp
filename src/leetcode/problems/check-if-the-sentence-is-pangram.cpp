#include "leetcode/problems/check-if-the-sentence-is-pangram.h"

namespace leetcode {
namespace problem_1832 {

namespace {

bool checkIfPangramImpl(std::string sentence) {
  bool seen[26] = {false};
  int count = 0;
  for (char c : sentence) {
    int idx = c - 'a';
    if (!seen[idx]) {
      seen[idx] = true;
      ++count;
    }
  }
  return count == 26;
}

}  // namespace

CheckIfTheSentenceIsPangramSolution::CheckIfTheSentenceIsPangramSolution() {
  setMetaInfo({.id = 1832,
               .title = "Check if the Sentence Is Pangram",
               .url = "https://leetcode.com/problems/check-if-the-sentence-is-pangram/"});
  registerStrategy(
      {.name = "BooleanMarker",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String"}},
      checkIfPangramImpl);
}

bool CheckIfTheSentenceIsPangramSolution::checkIfPangram(std::string sentence) {
  return getSolution()(sentence);
}

}  // namespace problem_1832
}  // namespace leetcode
