#include "leetcode/problems/find-the-number-of-winning-players.h"

namespace leetcode {
namespace problem_3238 {

namespace {

int winningPlayerCountImpl(int n, std::vector<std::vector<int>>& pick) {
  std::vector<std::vector<int>> count(n, std::vector<int>(11, 0));
  for (const auto& p : pick) {
    count[p[0]][p[1]]++;
  }
  int winners = 0;
  for (int i = 0; i < n; ++i) {
    for (int c = 0; c < 11; ++c) {
      if (count[i][c] > i) {
        ++winners;
        break;
      }
    }
  }
  return winners;
}

}  // namespace

FindTheNumberOfWinningPlayersSolution::FindTheNumberOfWinningPlayersSolution() {
  setMetaInfo({.id = 3238,
               .title = "Find the Number of Winning Players",
               .url = "https://leetcode.com/problems/find-the-number-of-winning-players/"});
  registerStrategy(
      {.name = "CountMatrix",
       .expected = "Accepted",
       .time_complexity = "O(pick.length + n * 11)",
       .space_complexity = "O(n * 11)",
       .tags = {"Array", "Hash Table", "Counting"}},
      winningPlayerCountImpl);
}

int FindTheNumberOfWinningPlayersSolution::winningPlayerCount(
    int n, std::vector<std::vector<int>>& pick) {
  return getSolution()(n, pick);
}

}  // namespace problem_3238
}  // namespace leetcode
