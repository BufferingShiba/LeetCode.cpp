#ifndef LEETCODE_PROBLEMS_MINIMUM_AVERAGE_OF_SMALLEST_AND_LARGEST_ELEMENTS_H__
#define LEETCODE_PROBLEMS_MINIMUM_AVERAGE_OF_SMALLEST_AND_LARGEST_ELEMENTS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3194 {

using Func = std::function<double(std::vector<int>&)>;

class MinimumAverageOfSmallestAndLargestElementsSolution
    : public SolutionBase<Func> {
 public:
  MinimumAverageOfSmallestAndLargestElementsSolution();

  double minimumAverage(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3194

#endif  // LEETCODE_PROBLEMS_MINIMUM_AVERAGE_OF_SMALLEST_AND_LARGEST_ELEMENTS_H__
