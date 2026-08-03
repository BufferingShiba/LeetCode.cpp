#ifndef LEETCODE_PROBLEMS_RECTANGLE_OVERLAP_H__
#define LEETCODE_PROBLEMS_RECTANGLE_OVERLAP_H__

#include <vector>
#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_836 {

using Func = std::function<bool(std::vector<int>&, std::vector<int>&)>;

class RectangleOverlapSolution : public SolutionBase<Func> {
 public:
  RectangleOverlapSolution();

  bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2);
};

}  // namespace problem_836
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_RECTANGLE_OVERLAP_H__
