#ifndef LEETCODE_PROBLEMS_UNIQUE_MIDDLE_ELEMENT_H__
#define LEETCODE_PROBLEMS_UNIQUE_MIDDLE_ELEMENT_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3978 {

using Func = std::function<bool(std::vector<int>&)>;

class UniqueMiddleElementSolution
    : public SolutionBase<Func> {
 public:
  UniqueMiddleElementSolution();
  bool isMiddleElementUnique(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3978

#endif  // LEETCODE_PROBLEMS_UNIQUE_MIDDLE_ELEMENT_H__
