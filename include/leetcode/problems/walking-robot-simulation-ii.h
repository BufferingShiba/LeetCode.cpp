#ifndef LEETCODE_PROBLEMS_WALKING_ROBOT_SIMULATION_II_H_
#define LEETCODE_PROBLEMS_WALKING_ROBOT_SIMULATION_II_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2069 {

using Func = std::function<std::vector<std::string>(
    const std::vector<std::string>& commands,
    const std::vector<std::vector<int>>& args)>;

class Robot {
 public:
  Robot(int width, int height);
  void step(int num);
  std::vector<int> getPos();
  std::string getDir();

 private:
  struct State {
    int x;
    int y;
    int dir;  // 0=East, 1=North, 2=West, 3=South
  };
  State currentState() const;

  int w_;
  int h_;
  long long pos_;  // absolute number of boundary steps walked
};

// O(1)-per-operation boundary-path mapping strategy.
std::vector<std::string> walkingRobotSimulationIiSolution(
    const std::vector<std::string>& commands,
    const std::vector<std::vector<int>>& args);

class WalkingRobotSimulationIiSolution : public SolutionBase<Func> {
 public:
  WalkingRobotSimulationIiSolution() {
    setMetaInfo({.id = 2069,
                 .title = "Walking Robot Simulation II",
                 .url = "https://leetcode.com/problems/walking-robot-simulation-ii/"});
    registerStrategy(
        {.name = "BoundaryPathMapping",
         .expected = "Accepted",
         .time_complexity = "O(1) per operation",
         .space_complexity = "O(1)",
         .tags = {"Design", "Simulation"}},
        walkingRobotSimulationIiSolution);
  }
};

}  // namespace problem_2069
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_WALKING_ROBOT_SIMULATION_II_H_
