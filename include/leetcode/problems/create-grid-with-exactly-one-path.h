#ifndef LEETCODE_PROBLEMS_CREATE_GRID_WITH_EXACTLY_ONE_PATH_H__
#define LEETCODE_PROBLEMS_CREATE_GRID_WITH_EXACTLY_ONE_PATH_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3963 {

using Func = std::function<std::vector<std::string>(int, int)>;

class CreateGridWithExactlyOnePathSolution : public SolutionBase<Func> {
 public:
  CreateGridWithExactlyOnePathSolution();

  std::vector<std::string> createGrid(int m, int n);
};

}  // namespace problem_3963
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CREATE_GRID_WITH_EXACTLY_ONE_PATH_H__
