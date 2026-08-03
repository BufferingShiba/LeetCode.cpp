#ifndef LEETCODE_PROBLEMS_ROBOT_RETURN_TO_ORIGIN_H__
#define LEETCODE_PROBLEMS_ROBOT_RETURN_TO_ORIGIN_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_657 {

using Func = std::function<bool(std::string)>;

class RobotReturnToOriginSolution : public SolutionBase<Func> {
 public:
  RobotReturnToOriginSolution();

  bool judgeCircle(std::string moves);
};

}  // namespace leetcode::problem_657

#endif  // LEETCODE_PROBLEMS_ROBOT_RETURN_TO_ORIGIN_H__
