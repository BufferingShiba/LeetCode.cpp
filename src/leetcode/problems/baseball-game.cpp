#include "leetcode/problems/baseball-game.h"

#include <numeric>
#include <string>
#include <vector>

namespace leetcode::problem_682 {

static int calPointsImpl(std::vector<std::string>& operations) {
  std::vector<int> scores;
  for (const std::string& op : operations) {
    if (op == "+") {
      int n = static_cast<int>(scores.size());
      scores.push_back(scores[n - 1] + scores[n - 2]);
    } else if (op == "D") {
      scores.push_back(scores.back() * 2);
    } else if (op == "C") {
      scores.pop_back();
    } else {
      scores.push_back(std::stoi(op));
    }
  }
  return std::accumulate(scores.begin(), scores.end(), 0);
}

BaseballGameSolution::BaseballGameSolution() {
  setMetaInfo({.id = 682,
                .title = "Baseball Game",
                .url = "https://leetcode.com/problems/baseball-game/"});
  registerStrategy(
      {.name = "Stack Simulation",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Stack", "Simulation"}},
      calPointsImpl);
  setDefaultStrategy();
}

int BaseballGameSolution::calPoints(std::vector<std::string>& operations) {
  return getSolution()(operations);
}

}  // namespace leetcode::problem_682
