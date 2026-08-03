#ifndef LEETCODE_PROBLEMS_MAXIMUM_DIFFERENCE_BETWEEN_INCREASING_ELEMENTS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_DIFFERENCE_BETWEEN_INCREASING_ELEMENTS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2016 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumDifferenceBetweenIncreasingElementsSolution
    : public SolutionBase<Func> {
 public:
  MaximumDifferenceBetweenIncreasingElementsSolution();

  int maximumDifference(std::vector<int>& nums);
};

}  // namespace problem_2016
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_DIFFERENCE_BETWEEN_INCREASING_ELEMENTS_H__
