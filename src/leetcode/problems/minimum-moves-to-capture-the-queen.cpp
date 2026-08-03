#include "leetcode/problems/minimum-moves-to-capture-the-queen.h"

#include <algorithm>
#include <cstdlib>

namespace leetcode::problem_3001 {

namespace {

int minMovesToCaptureTheQueenImpl(int a, int b, int c, int d, int e, int f) {
  // 1) Rook captures in one move: same row or same column, bishop not blocking
  if (a == e) {
    // same row — bishop blocks only if it's also in this row and between
    bool blocked = (c == e && std::min(b, f) < d && d < std::max(b, f));
    if (!blocked) return 1;
  }
  if (b == f) {
    // same column — bishop blocks only if it's also in this column and between
    bool blocked = (d == f && std::min(a, e) < c && c < std::max(a, e));
    if (!blocked) return 1;
  }

  // 2) Bishop captures in one move: same diagonal, rook not blocking
  if (std::abs(c - e) == std::abs(d - f)) {
    bool rookBlocks = false;
    // Rook blocks only if it lies on the same diagonal and strictly between
    if (std::abs(a - c) == std::abs(b - d) &&  // rook and bishop on same diagonal
        std::abs(a - e) == std::abs(b - f)) {  // rook and queen on same diagonal
      if (std::min(c, e) < a && a < std::max(c, e)) {
        rookBlocks = true;
      }
    }
    if (!rookBlocks) return 1;
  }

  // Otherwise need at least two moves (and two is always sufficient)
  return 2;
}

}  // namespace

MinimumMovesToCaptureTheQueenSolution::MinimumMovesToCaptureTheQueenSolution() {
  setMetaInfo({.id = 3001,
               .title = "Minimum Moves to Capture The Queen",
               .url = "https://leetcode.com/problems/minimum-moves-to-capture-the-queen/"});
  registerStrategy(
      {.name = "Enumeration",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Enumeration"}},
      minMovesToCaptureTheQueenImpl);
}

int MinimumMovesToCaptureTheQueenSolution::minMovesToCaptureTheQueen(int a, int b, int c,
                                                                      int d, int e, int f) {
  return getSolution()(a, b, c, d, e, f);
}

}  // namespace leetcode::problem_3001
