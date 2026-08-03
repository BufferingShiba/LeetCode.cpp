#include "leetcode/problems/minimum-time-to-revert-word-to-initial-state-i.h"

namespace leetcode::problem_3029 {
namespace {

int minimumTimeToInitialStateImpl(const std::string& word, int k) {
  const int n = static_cast<int>(word.size());
  int t = 1;
  while (true) {
    const int offset = k * t;
    if (offset >= n) {
      return t;  // All original characters removed; can rebuild the full word.
    }
    // Remaining suffix word[offset:] must match the prefix word[:n-offset].
    bool ok = true;
    for (int i = offset; i < n; ++i) {
      if (word[i] != word[i - offset]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      return t;
    }
    ++t;
  }
}

}  // namespace

MinimumTimeToRevertWordToInitialStateISolution::
    MinimumTimeToRevertWordToInitialStateISolution() {
  setMetaInfo({.id = 3029,
               .title = "Minimum Time to Revert Word to Initial State I",
               .url =
                   "https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-i/"});
  registerStrategy(
      {.name = "PrefixMatchBruteForce",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(1)",
       .tags = {"String", "String Matching"}},
      minimumTimeToInitialStateImpl);
}

int MinimumTimeToRevertWordToInitialStateISolution::
    minimumTimeToInitialState(std::string word, int k) {
  return getSolution()(std::move(word), k);
}

}  // namespace leetcode::problem_3029
