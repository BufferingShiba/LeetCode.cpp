#ifndef LEETCODE_PROBLEMS_LARGEST_PERIMETER_TRIANGLE_H__
#define LEETCODE_PROBLEMS_LARGEST_PERIMETER_TRIANGLE_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_976 {

using Func = std::function<int(std::vector<int>&)>;

class LargestPerimeterTriangleSolution : public SolutionBase<Func> {
 public:
  LargestPerimeterTriangleSolution();

  int largestPerimeter(std::vector<int>& nums);
};

}  // namespace leetcode::problem_976

#endif  // LEETCODE_PROBLEMS_LARGEST_PERIMETER_TRIANGLE_H__
