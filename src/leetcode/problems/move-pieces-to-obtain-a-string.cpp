#include "leetcode/problems/move-pieces-to-obtain-a-string.h"

namespace leetcode {
namespace problem_2337 {

static bool canChangeImpl(std::string start, std::string target) {
  int n = static_cast<int>(start.size());
  int i = 0, j = 0;

  while (i < n || j < n) {
    // Skip blanks in start
    while (i < n && start[i] == '_') ++i;
    // Skip blanks in target
    while (j < n && target[j] == '_') ++j;

    // Both exhausted — success
    if (i == n && j == n) return true;
    // Only one exhausted — piece count mismatch
    if (i == n || j == n) return false;

    // Piece types must match
    if (start[i] != target[j]) return false;

    // Position constraints
    if (start[i] == 'L' && j > i) return false;  // L can only move left
    if (start[i] == 'R' && j < i) return false;  // R can only move right

    ++i;
    ++j;
  }

  return true;
}

MovePiecesToObtainAStringSolution::MovePiecesToObtainAStringSolution() {
  setMetaInfo({.id = 2337,
               .title = "Move Pieces to Obtain a String",
               .url = "https://leetcode.com/problems/move-pieces-to-obtain-a-string/"});
  registerStrategy(
      {.name = "two-pointers",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String"}},
      canChangeImpl);
}

bool MovePiecesToObtainAStringSolution::canChange(std::string start,
                                                   std::string target) {
  return getSolution()(std::move(start), std::move(target));
}

}  // namespace problem_2337
}  // namespace leetcode
