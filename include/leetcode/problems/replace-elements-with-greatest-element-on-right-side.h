#ifndef LEETCODE_REPLACE_ELEMENTS_WITH_GREATEST_ELEMENT_ON_RIGHT_SIDE_H__
#define LEETCODE_REPLACE_ELEMENTS_WITH_GREATEST_ELEMENT_ON_RIGHT_SIDE_H__

#include "leetcode/core.h"

namespace leetcode::problem_1299 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class ReplaceElementsWithGreatestElementOnRightSideSolution : public SolutionBase<Func> {
 public:
  ReplaceElementsWithGreatestElementOnRightSideSolution();

  std::vector<int> replaceElements(std::vector<int>& arr);
};

}  // namespace leetcode::problem_1299

#endif  // LEETCODE_REPLACE_ELEMENTS_WITH_GREATEST_ELEMENT_ON_RIGHT_SIDE_H__
