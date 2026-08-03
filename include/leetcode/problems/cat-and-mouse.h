#ifndef LEETCODE_PROBLEMS_CAT_AND_MOUSE_H__
#define LEETCODE_PROBLEMS_CAT_AND_MOUSE_H__

#include "leetcode/core.h"

namespace leetcode::problem_913 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class CatAndMouseSolution : public SolutionBase<Func> {
 public:
  CatAndMouseSolution();
};

}  // namespace leetcode::problem_913

#endif  // LEETCODE_PROBLEMS_CAT_AND_MOUSE_H__
