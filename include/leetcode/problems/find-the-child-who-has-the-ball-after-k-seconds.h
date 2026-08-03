#ifndef LEETCODE_PROBLEMS_FIND_THE_CHILD_WHO_HAS_THE_BALL_AFTER_K_SECONDS_H__
#define LEETCODE_PROBLEMS_FIND_THE_CHILD_WHO_HAS_THE_BALL_AFTER_K_SECONDS_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_3178 {

using Func = std::function<int(int, int)>;

class FindTheChildWhoHasTheBallAfterKSecondsSolution : public SolutionBase<Func> {
 public:
  FindTheChildWhoHasTheBallAfterKSecondsSolution();

  int numberOfChild(int n, int k);
};

}  // namespace leetcode::problem_3178

#endif  // LEETCODE_PROBLEMS_FIND_THE_CHILD_WHO_HAS_THE_BALL_AFTER_K_SECONDS_H__
