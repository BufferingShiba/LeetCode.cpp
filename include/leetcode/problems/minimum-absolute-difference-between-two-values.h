#ifndef LEETCODE_PROBLEMS_MINIMUM_ABSOLUTE_DIFFERENCE_BETWEEN_TWO_VALUES_H__
#define LEETCODE_PROBLEMS_MINIMUM_ABSOLUTE_DIFFERENCE_BETWEEN_TWO_VALUES_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3880 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumAbsoluteDifferenceBetweenTwoValuesSolution
    : public SolutionBase<Func> {
 public:
  MinimumAbsoluteDifferenceBetweenTwoValuesSolution();

  int minAbsoluteDifference(std::vector<int>& nums);
};

}  // namespace problem_3880
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_ABSOLUTE_DIFFERENCE_BETWEEN_TWO_VALUES_H__
