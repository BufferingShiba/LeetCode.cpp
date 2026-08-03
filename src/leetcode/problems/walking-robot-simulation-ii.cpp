#include "leetcode/problems/walking-robot-simulation-ii.h"

namespace leetcode {
namespace problem_2069 {

namespace {

const std::vector<std::string>& kDirs() {
  static const std::vector<std::string> dirs = {"East", "North", "West", "South"};
  return dirs;
}

}  // namespace

Robot::Robot(int width, int height) : w_(width), h_(height), pos_(0) {}

void Robot::step(int num) { pos_ += num; }

Robot::State Robot::currentState() const {
  const long long P = 2LL * (w_ - 1) + 2LL * (h_ - 1);
  const long long k = pos_ % P;

  // Origin (0,0): faces East initially, but faces South after completing a lap.
  if (k == 0) {
    return {0, 0, pos_ == 0 ? 0 : 3};  // East=0, South=3
  }

  // Bottom edge: (x, 0), x in [1, w-1], arriving direction East.
  if (k <= w_ - 1) {
    return {static_cast<int>(k), 0, 0};
  }

  // Right column: (w-1, y), y in [1, h-1], arriving direction North.
  if (k <= static_cast<long long>(w_) + h_ - 2) {
    return {w_ - 1, static_cast<int>(k - w_ + 1), 1};
  }

  // Top edge: y = h-1, x in [w-2, 0], arriving direction West.
  if (k <= 2LL * w_ + h_ - 3) {
    const int x = static_cast<int>(w_ - 2 - (k - (w_ + h_ - 1)));
    return {x, h_ - 1, 2};
  }

  // Left column: x = 0, y in [h-2, 1], arriving direction South.
  const int y = static_cast<int>(h_ - 2 - (k - (2LL * w_ + h_ - 2)));
  return {0, y, 3};
}

std::vector<int> Robot::getPos() {
  const State s = currentState();
  return {s.x, s.y};
}

std::string Robot::getDir() {
  const State s = currentState();
  return kDirs()[s.dir];
}

std::vector<std::string> walkingRobotSimulationIiSolution(
    const std::vector<std::string>& commands,
    const std::vector<std::vector<int>>& args) {
  std::vector<std::string> out;
  out.reserve(commands.size());
  Robot* robot = nullptr;
  for (size_t i = 0; i < commands.size(); ++i) {
    if (commands[i] == "Robot") {
      robot = new Robot(args[i][0], args[i][1]);
      out.push_back("null");
    } else if (commands[i] == "step") {
      robot->step(args[i][0]);
      out.push_back("null");
    } else if (commands[i] == "getPos") {
      const auto p = robot->getPos();
      out.push_back("[" + std::to_string(p[0]) + "," + std::to_string(p[1]) + "]");
    } else {  // getDir
      out.push_back(robot->getDir());
    }
  }
  delete robot;
  return out;
}

}  // namespace problem_2069
}  // namespace leetcode
