#include "leetcode/problems/robot-bounded-in-circle.h"

namespace leetcode::problem_1041 {

namespace {

bool isRobotBoundedImpl(std::string instructions) {
  // direction: 0 = North, 1 = East, 2 = South, 3 = West
  int x = 0, y = 0, dir = 0;

  // direction vectors for N, E, S, W
  const int dx[4] = {0, 1, 0, -1};
  const int dy[4] = {1, 0, -1, 0};

  for (char c : instructions) {
    if (c == 'G') {
      x += dx[dir];
      y += dy[dir];
    } else if (c == 'L') {
      dir = (dir + 3) % 4;  // turn left (anti-clockwise)
    } else {  // 'R'
      dir = (dir + 1) % 4;  // turn right (clockwise)
    }
  }

  // Bounded iff back to origin OR direction changed
  return (x == 0 && y == 0) || dir != 0;
}

}  // namespace

RobotBoundedInCircleSolution::RobotBoundedInCircleSolution() {
  setMetaInfo({.id = 1041,
               .title = "Robot Bounded In Circle",
               .url = "https://leetcode.com/problems/robot-bounded-in-circle/"});

  registerStrategy(
      {.name = "Simulation",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Math", "String", "Simulation"}},
      isRobotBoundedImpl);

  setDefaultStrategy();
}

bool RobotBoundedInCircleSolution::isRobotBounded(std::string instructions) {
  return getSolution()(instructions);
}

}  // namespace leetcode::problem_1041
