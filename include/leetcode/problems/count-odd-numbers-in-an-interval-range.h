#ifndef LEETCODE_PROBLEMS_COUNT_ODD_NUMBERS_IN_AN_INTERVAL_RANGE_H__
#define LEETCODE_PROBLEMS_COUNT_ODD_NUMBERS_IN_AN_INTERVAL_RANGE_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode {
namespace problem_1523 {

using Func = std::function<int(int, int)>;

class CountOddNumbersInAnIntervalRangeSolution
    : public SolutionBase<Func> {
 public:
  CountOddNumbersInAnIntervalRangeSolution();

  int countOdds(int low, int high);
};

}  // namespace problem_1523
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_ODD_NUMBERS_IN_AN_INTERVAL_RANGE_H__
