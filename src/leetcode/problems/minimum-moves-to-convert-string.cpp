#include "leetcode/problems/minimum-moves-to-convert-string.h"

namespace leetcode::problem_2027 {

namespace {

int minimumMovesImpl(std::string s) {
  int moves = 0;
  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    if (s[i] == 'X') {
      ++moves;
      i += 2;  // skip the next 2 chars covered by this move
    }
  }
  return moves;
}

}  // namespace

MinimumMovesToConvertStringSolution::MinimumMovesToConvertStringSolution() {
  setMetaInfo({.id = 2027,
               .title = "Minimum Moves to Convert String",
               .url = "https://leetcode.com/problems/minimum-moves-to-convert-string/"});
  registerStrategy({.name = "GreedyScan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"String", "Greedy"}},
                   minimumMovesImpl);
}

int MinimumMovesToConvertStringSolution::minimumMoves(std::string s) {
  return getSolution()(s);
}

}  // namespace leetcode::problem_2027
