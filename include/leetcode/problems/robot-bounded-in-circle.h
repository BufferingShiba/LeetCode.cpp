#ifndef LEETCODE_PROBLEM_1041_H__
#define LEETCODE_PROBLEM_1041_H__

#include "leetcode/core.h"

namespace leetcode::problem_1041 {

using Func = std::function<bool(std::string)>;

class RobotBoundedInCircleSolution : public SolutionBase<Func> {
 public:
  RobotBoundedInCircleSolution();

  bool isRobotBounded(std::string instructions);
};

}  // namespace leetcode::problem_1041

#endif  // LEETCODE_PROBLEM_1041_H__
