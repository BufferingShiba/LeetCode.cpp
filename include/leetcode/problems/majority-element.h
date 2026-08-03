#ifndef LEETCODE_PROBLEMS_MAJORITY_ELEMENT_H__
#define LEETCODE_PROBLEMS_MAJORITY_ELEMENT_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_169 {

using Func = std::function<int(std::vector<int>&)>;

class MajorityElementSolution : public SolutionBase<Func> {
 public:
  MajorityElementSolution();

  int majorityElement(std::vector<int>& nums);
};

}  // namespace leetcode::problem_169

#endif  // LEETCODE_PROBLEMS_MAJORITY_ELEMENT_H__
