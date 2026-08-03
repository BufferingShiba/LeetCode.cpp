#ifndef LEETCODE_PROBLEMS_COUNT_COMMAS_IN_RANGE_H__
#define LEETCODE_PROBLEMS_COUNT_COMMAS_IN_RANGE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3870 {

using Func = std::function<int(int)>;

class CountCommasInRangeSolution : public SolutionBase<Func> {
 public:
  CountCommasInRangeSolution();

  int countCommas(int n);
};

}  // namespace leetcode::problem_3870

#endif  // LEETCODE_PROBLEMS_COUNT_COMMAS_IN_RANGE_H__
