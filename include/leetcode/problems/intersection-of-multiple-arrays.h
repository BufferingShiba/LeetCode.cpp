#ifndef LEETCODE_PROBLEMS_INTERSECTION_OF_MULTIPLE_ARRAYS_H__
#define LEETCODE_PROBLEMS_INTERSECTION_OF_MULTIPLE_ARRAYS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2248 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&)>;

class IntersectionOfMultipleArraysSolution
    : public SolutionBase<Func> {
 public:
  IntersectionOfMultipleArraysSolution();

  std::vector<int> intersection(std::vector<std::vector<int>>& nums);
};

}  // namespace leetcode::problem_2248

#endif  // LEETCODE_PROBLEMS_INTERSECTION_OF_MULTIPLE_ARRAYS_H__
