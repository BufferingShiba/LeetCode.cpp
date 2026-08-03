#include "leetcode/problems/robot-return-to-origin.h"

namespace leetcode::problem_657 {

namespace {

bool judgeCircleImpl(const std::string& moves) {
  int x = 0;
  int y = 0;
  for (char c : moves) {
    switch (c) {
      case 'U':
        ++y;
        break;
      case 'D':
        --y;
        break;
      case 'L':
        --x;
        break;
      case 'R':
        ++x;
        break;
      default:
        break;
    }
  }
  return x == 0 && y == 0;
}

}  // namespace

RobotReturnToOriginSolution::RobotReturnToOriginSolution() {
  setMetaInfo({.id = 657,
               .title = "Robot Return to Origin",
               .url =
                   "https://leetcode.com/problems/robot-return-to-origin/"});

  registerStrategy(
      {.name = "simulation",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Simulation"}},
      judgeCircleImpl);
}

bool RobotReturnToOriginSolution::judgeCircle(std::string moves) {
  return getSolution()(moves);
}

}  // namespace leetcode::problem_657
