#ifndef LEETCODE_PROBLEMS_COUNT_GOOD_INTEGERS_ON_A_GRID_PATH_H_
#define LEETCODE_PROBLEMS_COUNT_GOOD_INTEGERS_ON_A_GRID_PATH_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_3906 {

using Func = std::function<long long(long long, long long, std::string)>;

class CountGoodIntegersOnAGridPathSolution
    : public SolutionBase<Func> {
 public:
  CountGoodIntegersOnAGridPathSolution();

  long long countGoodIntegersOnPath(long long l, long long r,
                                    std::string directions);
};

}  // namespace leetcode::problem_3906

#endif  // LEETCODE_PROBLEMS_COUNT_GOOD_INTEGERS_ON_A_GRID_PATH_H_
