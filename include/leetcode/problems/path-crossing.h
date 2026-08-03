#ifndef LEETCODE_PROBLEMS_PATH_CROSSING_H__
#define LEETCODE_PROBLEMS_PATH_CROSSING_H__

#include <string>
#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_1496 {

class PathCrossingSolution : public SolutionBase<std::function<bool(std::string)>> {
 public:
  bool isPathCrossing(std::string path);

  PathCrossingSolution();
};

}  // namespace leetcode::problem_1496

#endif  // LEETCODE_PROBLEMS_PATH_CROSSING_H__
