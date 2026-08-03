#ifndef LEETCODE_PROBLEMS_LARGEST_TRIANGLE_AREA_H__
#define LEETCODE_PROBLEMS_LARGEST_TRIANGLE_AREA_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_812 {

using Func = std::function<double(std::vector<std::vector<int>>&)>;

class LargestTriangleAreaSolution : public SolutionBase<Func> {
 public:
  LargestTriangleAreaSolution();

  double largestTriangleArea(std::vector<std::vector<int>>& points);
};

}  // namespace problem_812
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LARGEST_TRIANGLE_AREA_H__
