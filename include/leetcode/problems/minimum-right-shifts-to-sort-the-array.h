#ifndef LEETCODE_PROBLEMS_MINIMUM_RIGHT_SHIFTS_TO_SORT_THE_ARRAY_H_
#define LEETCODE_PROBLEMS_MINIMUM_RIGHT_SHIFTS_TO_SORT_THE_ARRAY_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2855 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumRightShiftsToSortTheArraySolution
    : public SolutionBase<Func> {
 public:
  MinimumRightShiftsToSortTheArraySolution();

  int minimumRightShifts(std::vector<int>& nums);
};

}  // namespace problem_2855
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_RIGHT_SHIFTS_TO_SORT_THE_ARRAY_H_
