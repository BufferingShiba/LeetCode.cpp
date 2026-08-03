#ifndef LEETCODE_PROBLEMS_CAT_AND_MOUSE_II_H_
#define LEETCODE_PROBLEMS_CAT_AND_MOUSE_II_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1728 {

using Func = std::function<bool(std::vector<std::string>&, int, int)>;

class CatAndMouseIiSolution : public SolutionBase<Func> {
 public:
  CatAndMouseIiSolution();

  bool canMouseWin(std::vector<std::string>& grid, int catJump, int mouseJump);
};

}  // namespace leetcode::problem_1728

#endif  // LEETCODE_PROBLEMS_CAT_AND_MOUSE_II_H_
