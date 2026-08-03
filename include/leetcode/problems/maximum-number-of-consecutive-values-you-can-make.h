#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_CONSECUTIVE_VALUES_YOU_CAN_MAKE_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_CONSECUTIVE_VALUES_YOU_CAN_MAKE_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1798 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumNumberOfConsecutiveValuesYouCanMakeSolution
    : public SolutionBase<Func> {
 public:
  MaximumNumberOfConsecutiveValuesYouCanMakeSolution();

  int getMaximumConsecutive(std::vector<int>& coins) {
    return getSolution()(coins);
  }
};

}  // namespace problem_1798
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_CONSECUTIVE_VALUES_YOU_CAN_MAKE_H__
