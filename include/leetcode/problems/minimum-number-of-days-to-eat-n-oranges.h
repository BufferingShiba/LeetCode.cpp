#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_DAYS_TO_EAT_N_ORANGES_H__
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_DAYS_TO_EAT_N_ORANGES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1553 {

using Func = std::function<int(int)>;

class MinimumNumberOfDaysToEatNOrangesSolution
    : public SolutionBase<Func> {
 public:
  MinimumNumberOfDaysToEatNOrangesSolution();

  int minDays(int n);
};

}  // namespace problem_1553
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_DAYS_TO_EAT_N_ORANGES_H__
