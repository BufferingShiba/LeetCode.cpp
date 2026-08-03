#ifndef LEETCODE_PROBLEMS_HEIGHT_CHECKER_H_
#define LEETCODE_PROBLEMS_HEIGHT_CHECKER_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1051 {

using Func = std::function<int(std::vector<int>&)>;

class HeightCheckerSolution : public SolutionBase<Func> {
 public:
  HeightCheckerSolution();

  int heightChecker(std::vector<int>& heights);
};

}  // namespace leetcode::problem_1051

#endif  // LEETCODE_PROBLEMS_HEIGHT_CHECKER_H_
