#include "leetcode/problems/find-players-with-zero-or-one-losses.h"

namespace leetcode {
namespace problem_2225 {

namespace {

std::vector<std::vector<int>> findWinnersImpl(std::vector<std::vector<int>>& matches) {
  constexpr int kMaxPlayer = 100000;
  // losses[i] = -1  → player i never appeared
  // losses[i] =  0  → appeared, zero losses
  // losses[i] >= 1  → appeared, lost that many times
  std::vector<int> losses(kMaxPlayer + 1, -1);

  for (const auto& match : matches) {
    int winner = match[0];
    int loser = match[1];

    if (losses[winner] == -1) {
      losses[winner] = 0;
    }
    if (losses[loser] == -1) {
      losses[loser] = 1;
    } else {
      ++losses[loser];
    }
  }

  std::vector<std::vector<int>> answer(2);
  for (int i = 1; i <= kMaxPlayer; ++i) {
    if (losses[i] == 0) {
      answer[0].push_back(i);
    } else if (losses[i] == 1) {
      answer[1].push_back(i);
    }
  }

  return answer;
}

}  // namespace

FindPlayersWithZeroOrOneLossesSolution::FindPlayersWithZeroOrOneLossesSolution() {
  setMetaInfo({.id = 2225,
               .title = "Find Players With Zero or One Losses",
               .url = "https://leetcode.com/problems/find-players-with-zero-or-one-losses/"});
  registerStrategy({.name = "Counting Array",
                    .expected = "Accepted",
                    .time_complexity = "O(N + M)",
                    .space_complexity = "O(M)",
                    .tags = {"Array", "Hash Table", "Counting"}},
                   findWinnersImpl);
}

std::vector<std::vector<int>> FindPlayersWithZeroOrOneLossesSolution::findWinners(
    std::vector<std::vector<int>>& matches) {
  return getSolution()(matches);
}

}  // namespace problem_2225
}  // namespace leetcode
