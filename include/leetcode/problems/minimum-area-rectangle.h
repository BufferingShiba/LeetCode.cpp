#ifndef LEETCODE_PROBLEMS_MINIMUM_AREA_RECTANGLE_H_
#define LEETCODE_PROBLEMS_MINIMUM_AREA_RECTANGLE_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_939 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MinimumAreaRectangleSolution
    : public SolutionBase<Func> {
 public:
  MinimumAreaRectangleSolution();

  int minAreaRect(std::vector<std::vector<int>>& points);
};

}  // namespace problem_939
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_AREA_RECTANGLE_H_
