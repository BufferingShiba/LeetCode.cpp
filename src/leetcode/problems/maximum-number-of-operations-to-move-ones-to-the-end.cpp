#include "leetcode/problems/maximum-number-of-operations-to-move-ones-to-the-end.h"

#include <string>

namespace leetcode::problem_3228 {

namespace {

int maxOperationsImpl(const std::string& s) {
  int ans = 0;
  int ones = 0;
  const int n = static_cast<int>(s.size());
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      ++ones;
    } else if (i + 1 < n && s[i + 1] == '1') {
      // This '0' is the end of a zero block whose right side contains ones,
      // so every '1' seen so far can cross this zero block once.
      ans += ones;
    }
  }
  return ans;
}

}  // namespace

MaximumNumberOfOperationsToMoveOnesToTheEndSolution::
    MaximumNumberOfOperationsToMoveOnesToTheEndSolution() {
  setMetaInfo({.id = 3228,
               .title = "Maximum Number of Operations to Move Ones to the End",
               .url = "https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/"});
  registerStrategy(
      {.name = "GreedyCounting",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Greedy", "Counting"}},
      maxOperationsImpl);
}

int MaximumNumberOfOperationsToMoveOnesToTheEndSolution::maxOperations(
    const std::string& s) {
  return getSolution()(s);
}

}  // namespace leetcode::problem_3228
