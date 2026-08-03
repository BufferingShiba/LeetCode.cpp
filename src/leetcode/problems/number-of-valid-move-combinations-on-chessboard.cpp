#include "leetcode/problems/number-of-valid-move-combinations-on-chessboard.h"

#include <algorithm>
#include <functional>

namespace leetcode {
namespace problem_2056 {

namespace {

// Directions: index 0..3 orthogonal (rook), 0..7 all (queen), 4..7 diagonal (bishop).
const int kDR[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kDC[8] = {0, 0, 1, -1, 1, -1, 1, -1};

// Returns the first direction index to consider.
inline int directionStartForType(const std::string& type) {
  return type[0] == 'b' ? 4 : 0;  // bishop uses only diagonal dirs.
}

inline int directionCountForType(const std::string& type) {
  // 'r' rook -> 4, 'q' queen -> 8, 'b' bishop -> 4.
  return type[0] == 'q' ? 8 : 4;
}

int countCombinationsImpl(std::vector<std::string>& pieces,
                          std::vector<std::vector<int>>& positions) {
  const int n = static_cast<int>(pieces.size());
  int result = 0;

  // chosen[i] = {direction, steps}; steps == 0 means the piece stays put.
  std::vector<std::pair<int, int>> chosen(n);

  // Simulate time for a fully chosen move combination.
  auto valid = [&]() -> bool {
    int T = 0;
    for (int i = 0; i < n; ++i) T = std::max(T, chosen[i].second);

    for (int t = 0; t <= T; ++t) {
      std::vector<std::pair<int, int>> cur(n);
      for (int i = 0; i < n; ++i) {
        const int steps = std::min(chosen[i].second, t);  // clamped at destination
        const int d = chosen[i].first;
        cur[i] = {positions[i][0] + kDR[d] * steps, positions[i][1] + kDC[d] * steps};
      }
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (cur[i] == cur[j]) return false;
        }
      }
    }
    return true;
  };

  std::function<void(int)> dfs = [&](int idx) {
    if (idx == n) {
      if (valid()) ++result;
      return;
    }

    // Option 1: stay on the current square (steps = 0).
    chosen[idx] = {0, 0};
    dfs(idx + 1);

    // Option 2: move along one of the allowed directions by 1..boundary steps.
    const int r0 = positions[idx][0];
    const int c0 = positions[idx][1];
    const int dstart = directionStartForType(pieces[idx]);
    const int ndir = directionCountForType(pieces[idx]);
    for (int d = dstart; d < dstart + ndir; ++d) {
      int steps = 1;
      while (true) {
        const int r = r0 + kDR[d] * steps;
        const int c = c0 + kDC[d] * steps;
        if (r < 1 || r > 8 || c < 1 || c > 8) break;
        chosen[idx] = {d, steps};
        dfs(idx + 1);
        ++steps;
      }
    }
  };

  dfs(0);
  return result;
}

}  // namespace

NumberOfValidMoveCombinationsOnChessboardSolution::
    NumberOfValidMoveCombinationsOnChessboardSolution() {
  this->setMetaInfo({.id = 2056,
                     .title = "Number of Valid Move Combinations On Chessboard",
                     .url = "https://leetcode.com/problems/number-of-valid-move-combinations-on-chessboard/"});
  this->registerStrategy(
      {.name = "BacktrackingSimulation",
       .expected = "Accepted",
       .time_complexity = "O(4^n * maxSteps * n^2)",
       .space_complexity = "O(n)",
       .tags = {"Backtracking", "Simulation"},
       .notes =
           "Enumerate every piece's (direction, steps) choice (or stay put), then "
           "simulate time second by second and reject any collision at any time step."},
      countCombinationsImpl);
}

int NumberOfValidMoveCombinationsOnChessboardSolution::countCombinations(
    std::vector<std::string>& pieces, std::vector<std::vector<int>>& positions) {
  return this->getSolution()(pieces, positions);
}

}  // namespace problem_2056
}  // namespace leetcode
