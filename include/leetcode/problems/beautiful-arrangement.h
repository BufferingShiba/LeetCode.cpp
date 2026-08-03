#ifndef LEETCODE_PROBLEM_526_H__
#define LEETCODE_PROBLEM_526_H__

#include "leetcode/core.h"

namespace leetcode::problem_526 {

using Func = std::function<int(int)>;

class BeautifulArrangementSolution : public SolutionBase<Func> {
 public:
  BeautifulArrangementSolution();

  int countArrangement(int n);
};

}  // namespace leetcode::problem_526

#endif  // LEETCODE_PROBLEM_526_H__
