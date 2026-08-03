#include <string>
#include <vector>

#include "leetcode/problems/snake-in-matrix.h"

namespace leetcode {
namespace problem_3248 {
namespace {

int finalPositionOfSnakeImpl(int n, std::vector<std::string>& commands) {
  int i = 0, j = 0;
  for (const auto& cmd : commands) {
    if (cmd == "UP") {
      --i;
    } else if (cmd == "DOWN") {
      ++i;
    } else if (cmd == "LEFT") {
      --j;
    } else {  // "RIGHT"
      ++j;
    }
  }
  return i * n + j;
}

}  // namespace

SnakeInMatrixSolution::SnakeInMatrixSolution() {
  setMetaInfo({.id = 3248,
               .title = "Snake in Matrix",
               .url = "https://leetcode.com/problems/snake-in-matrix/"});
  registerStrategy(
      {.name = "simulation",
       .expected = "Accepted",
       .time_complexity = "O(k) where k = commands.length",
       .space_complexity = "O(1)",
       .tags = {"Array", "String", "Simulation"}},
      finalPositionOfSnakeImpl);
}

int SnakeInMatrixSolution::finalPositionOfSnake(int n,
                                                std::vector<std::string>& commands) {
  return getSolution()(n, commands);
}

}  // namespace problem_3248
}  // namespace leetcode
