#include "leetcode/problems/check-if-string-is-transformable-with-substring-sort-operations.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_1585 {

namespace {

// Greedy: for each position i in t, match the corresponding occurrence of the
// same digit in s. A matching is valid iff before that matched position in s,
// the count of digits smaller than c is <= the count of such digits already
// consumed in t. Since sorting only moves smaller digits leftwards, a large
// digit can never jump over a smaller one that must appear after it in t.
bool isTransformableImpl(std::string s, std::string t) {
  const int n = static_cast<int>(s.size());

  // For each digit, sorted list of positions where it appears in s.
  std::vector<std::vector<int>> pos(10);
  for (int i = 0; i < n; ++i) {
    pos[s[i] - '0'].push_back(i);
  }

  // used[d] = how many d's have been matched to t so far.
  std::vector<int> used(10, 0);

  for (int i = 0; i < n; ++i) {
    int c = t[i] - '0';
    if (used[c] >= static_cast<int>(pos[c].size())) {
      return false;  // t has more c's than s.
    }
    int p = pos[c][used[c]];
    ++used[c];

    // For every digit d < c, ensure the count of d appearing before p in s
    // does not exceed the number of d's already matched in t. Otherwise a
    // smaller digit would need to move rightwards past c, which sorting
    // (ascending) can never achieve.
    for (int d = 0; d < c; ++d) {
      auto& pd = pos[d];
      int cntInS = static_cast<int>(
          std::upper_bound(pd.begin(), pd.end(), p - 1) - pd.begin());
      if (cntInS > used[d]) {
        return false;
      }
    }
  }
  return true;
}

}  // namespace

bool CheckIfStringIsTransformableWithSubstringSortOperationsSolution::
    isTransformable(std::string s, std::string t) {
  return getSolution()(std::move(s), std::move(t));
}

CheckIfStringIsTransformableWithSubstringSortOperationsSolution::
    CheckIfStringIsTransformableWithSubstringSortOperationsSolution() {
  setMetaInfo({.id = 1585,
               .title =
                   "Check If String Is Transformable With Substring Sort "
                   "Operations",
               .url = "https://leetcode.com/problems/check-if-string-is-"
                      "transformable-with-substring-sort-operations/"});
  StrategyMetadata metadata;
  metadata.name = "Greedy finger-counting";
  metadata.expected = "Accepted";
  metadata.time_complexity = "O(10*n) = O(n)";
  metadata.space_complexity = "O(n)";
  metadata.tags = {"String", "Greedy", "Sorting"};
  registerStrategy(metadata, isTransformableImpl);
}

}  // namespace leetcode::problem_1585
