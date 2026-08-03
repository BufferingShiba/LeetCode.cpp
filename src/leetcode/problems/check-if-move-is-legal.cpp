#include "leetcode/problems/check-if-move-is-legal.h"

#include <array>

namespace leetcode {
namespace problem_1958 {

namespace {

// Directions: row delta, col delta.
const std::array<std::pair<int, int>, 8> kDirections = {{
    {-1, 0}, {1, 0}, {0, -1}, {0, 1},   // vertical & horizontal
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}, // diagonals
}};

bool checkMoveImpl(std::vector<std::vector<char>>& board, int rMove, int cMove,
                   char color) {
  const char opposite = (color == 'B') ? 'W' : 'B';

  for (const auto& [dr, dc] : kDirections) {
    int r = rMove + dr;
    int c = cMove + dc;
    bool seenOpposite = false;

    while (r >= 0 && r < 8 && c >= 0 && c < 8) {
      char cell = board[r][c];
      if (cell == '.') {
        break;  // free cell interrupts the line
      }
      if (cell == color) {
        // Reached an endpoint of same color: valid if we crossed >=1 opposite.
        if (seenOpposite) {
          return true;
        }
        break;  // same color immediately adjacent -> not a good line
      }
      // cell == opposite
      seenOpposite = true;
      r += dr;
      c += dc;
    }
  }

  return false;
}

}  // namespace

CheckIfMoveIsLegalSolution::CheckIfMoveIsLegalSolution() {
  setMetaInfo({.id = 1958,
               .title = "Check if Move is Legal",
               .url = "https://leetcode.com/problems/check-if-move-is-legal/"});

  registerStrategy(
      {.name = "DirectionEnumeration",
       .expected = "Accepted",
       .time_complexity = "O(64)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Matrix", "Enumeration"},
       .notes =
           "Brute-force each of the 8 directions; a good line forms if after at "
           "least one opposite-colored cell we reach the same color as an "
           "endpoint."},
      checkMoveImpl);
}

bool CheckIfMoveIsLegalSolution::checkMove(
    std::vector<std::vector<char>>& board, int rMove, int cMove, char color) {
  return getSolution()(board, rMove, cMove, color);
}

}  // namespace problem_1958
}  // namespace leetcode
