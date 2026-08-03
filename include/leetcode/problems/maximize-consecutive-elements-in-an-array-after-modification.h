#ifndef LEETCODE_PROBLEMS_MAXIMIZE_CONSECUTIVE_ELEMENTS_IN_AN_ARRAY_AFTER_MODIFICATION_H_
#define LEETCODE_PROBLEMS_MAXIMIZE_CONSECUTIVE_ELEMENTS_IN_AN_ARRAY_AFTER_MODIFICATION_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3041 {

using Func = std::function<int(std::vector<int>&)>;

class MaximizeConsecutiveElementsInAnArrayAfterModificationSolution : public SolutionBase<Func> {
 public:
  int maxSelectedElements(std::vector<int>& nums);

  MaximizeConsecutiveElementsInAnArrayAfterModificationSolution();
};

}  // namespace leetcode::problem_3041

#endif  // LEETCODE_PROBLEMS_MAXIMIZE_CONSECUTIVE_ELEMENTS_IN_AN_ARRAY_AFTER_MODIFICATION_H_
