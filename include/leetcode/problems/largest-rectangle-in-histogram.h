#ifndef LEETCODE_PROBLEMS_LARGEST_RECTANGLE_IN_HISTOGRAM_H__
#define LEETCODE_PROBLEMS_LARGEST_RECTANGLE_IN_HISTOGRAM_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_84 {

using Func = std::function<int(std::vector<int>&)>;

class LargestRectangleInHistogramSolution
    : public SolutionBase<Func> {
 public:
  LargestRectangleInHistogramSolution();

  int largestRectangleArea(std::vector<int>& heights) {
    return getSolution()(heights);
  }
};

}  // namespace problem_84
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LARGEST_RECTANGLE_IN_HISTOGRAM_H__
