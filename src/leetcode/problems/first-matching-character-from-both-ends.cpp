#include "leetcode/problems/first-matching-character-from-both-ends.h"

namespace leetcode::problem_3884 {

namespace {

int firstMatchingIndexImpl(std::string s) {
  const int n = static_cast<int>(s.size());
  for (int i = 0; i < n; ++i) {
    if (s[i] == s[n - i - 1]) {
      return i;
    }
  }
  return -1;
}

}  // namespace

int FirstMatchingCharacterFromBothEndsSolution::firstMatchingIndex(std::string s) {
  return getSolution()(s);
}

FirstMatchingCharacterFromBothEndsSolution::FirstMatchingCharacterFromBothEndsSolution()
    : SolutionBase() {
  this->setMetaInfo({.id = 3884,
                     .title = "First Matching Character From Both Ends",
                     .url = "https://leetcode.com/problems/first-matching-character-from-both-ends/"});
  this->registerStrategy({.name = "Two Pointers",
                          .expected = "Accepted",
                          .time_complexity = "O(n)",
                          .space_complexity = "O(1)",
                          .tags = {"Two Pointers", "String"}},
                         firstMatchingIndexImpl);
}

}  // namespace leetcode::problem_3884
