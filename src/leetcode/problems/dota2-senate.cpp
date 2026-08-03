#include "leetcode/problems/dota2-senate.h"

#include <queue>
#include <string>

namespace leetcode {
namespace problem_649 {

static std::string predictPartyVictoryImpl(std::string senate) {
  std::queue<int> radiant, dire;
  int n = static_cast<int>(senate.size());

  for (int i = 0; i < n; ++i) {
    if (senate[i] == 'R') {
      radiant.push(i);
    } else {
      dire.push(i);
    }
  }

  while (!radiant.empty() && !dire.empty()) {
    int r_idx = radiant.front();
    radiant.pop();
    int d_idx = dire.front();
    dire.pop();

    if (r_idx < d_idx) {
      radiant.push(r_idx + n);
    } else {
      dire.push(d_idx + n);
    }
  }

  return radiant.empty() ? "Dire" : "Radiant";
}

Dota2SenateSolution::Dota2SenateSolution() {
  setMetaInfo({.id = 649, .title = "Dota2 Senate", .url = "https://leetcode.com/problems/dota2-senate/"});
  registerStrategy(
      {.name = "GreedyTwoQueues",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"String", "Greedy", "Queue"}},
      predictPartyVictoryImpl);
  setDefaultStrategy();
}

std::string Dota2SenateSolution::predictPartyVictory(std::string senate) {
  return getSolution()(senate);
}

}  // namespace problem_649
}  // namespace leetcode
