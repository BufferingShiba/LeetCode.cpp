#include "leetcode/problems/calculate-score-after-performing-instructions.h"

namespace leetcode {
namespace problem_3522 {

namespace {

long long calculateScoreImpl(std::vector<std::string>& instructions,
                             std::vector<int>& values) {
  const int n = static_cast<int>(instructions.size());
  std::vector<bool> visited(n, false);
  long long score = 0;
  int i = 0;
  while (0 <= i && i < n) {
    if (visited[i]) {
      break;
    }
    visited[i] = true;
    if (instructions[i] == "add") {
      score += values[i];
      ++i;
    } else {  // "jump"
      i += values[i];
    }
  }
  return score;
}

}  // namespace

CalculateScoreAfterPerformingInstructionsSolution::
    CalculateScoreAfterPerformingInstructionsSolution() {
  setMetaInfo({.id = 3522,
               .title = "Calculate Score After Performing Instructions",
               .url = "https://leetcode.com/problems/calculate-score-after-performing-instructions/"});
  registerStrategy(
      {.name = "simulation_visited",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "String", "Simulation"}},
      calculateScoreImpl);
}

}  // namespace problem_3522
}  // namespace leetcode
