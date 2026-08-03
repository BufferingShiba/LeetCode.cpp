#include "leetcode/problems/swap-adjacent-in-lr-string.h"

#include <string>

namespace leetcode::problem_777 {

namespace {

// Two-pointer scan over the non-'X' characters of both strings.
// Key invariants:
//   1. Removing all 'X' from start and result must yield identical sequences
//      (L/R can never pass each other).
//   2. Each 'L' in start must sit at a position >= its position in result
//      ('L' only ever moves leftwards via XL -> LX).
//   3. Each 'R' in start must sit at a position <= its position in result
//      ('R' only ever moves rightwards via RX -> XR).
bool canTransformImpl(const std::string& start, const std::string& result) {
  if (start.size() != result.size()) {
    return false;
  }
  const int n = static_cast<int>(start.size());
  int i = 0;
  int j = 0;
  while (i < n || j < n) {
    // Advance to next non-'X' in start.
    while (i < n && start[i] == 'X') {
      ++i;
    }
    // Advance to next non-'X' in result.
    while (j < n && result[j] == 'X') {
      ++j;
    }
    if (i == n || j == n) {
      return i == n && j == n;
    }
    if (start[i] != result[j]) {
      return false;
    }
    if (start[i] == 'L' && i < j) {
      // 'L' cannot move right; its position must not increase.
      return false;
    }
    if (start[i] == 'R' && i > j) {
      // 'R' cannot move left; its position must not decrease.
      return false;
    }
    ++i;
    ++j;
  }
  return true;
}

}  // namespace

SwapAdjacentInLrStringSolution::SwapAdjacentInLrStringSolution() {
  setMetaInfo({.id = 777,
               .title = "Swap Adjacent in LR String",
               .url = "https://leetcode.com/problems/swap-adjacent-in-lr-string/"});
  registerStrategy(
      {.name = "TwoPointers",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String"}},
      static_cast<bool (*)(const std::string&, const std::string&)>(canTransformImpl));
}

bool SwapAdjacentInLrStringSolution::canTransform(const std::string& start,
                                                   const std::string& result) {
  return getSolution()(start, result);
}

}  // namespace leetcode::problem_777
