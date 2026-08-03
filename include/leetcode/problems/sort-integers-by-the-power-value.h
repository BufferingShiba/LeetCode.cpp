#ifndef LEETCODE_PROBLEMS_SORT_INTEGERS_BY_THE_POWER_VALUE_H__
#define LEETCODE_PROBLEMS_SORT_INTEGERS_BY_THE_POWER_VALUE_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode {
namespace problem_1387 {

using Func = std::function<int(int, int, int)>;

class SortIntegersByThePowerValueSolution : public SolutionBase<Func> {
 public:
  SortIntegersByThePowerValueSolution();

  // Original problem method.
  int getKth(int lo, int hi, int k);
};

}  // namespace problem_1387
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SORT_INTEGERS_BY_THE_POWER_VALUE_H__
