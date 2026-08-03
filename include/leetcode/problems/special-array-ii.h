#ifndef LEETCODE_PROBLEMS_SPECIAL_ARRAY_II_H__
#define LEETCODE_PROBLEMS_SPECIAL_ARRAY_II_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3152 {

using Func = std::function<std::vector<bool>(std::vector<int>&,
                                             std::vector<std::vector<int>>&)>;

class SpecialArrayIiSolution : public SolutionBase<Func> {
 public:
  SpecialArrayIiSolution();

  std::vector<bool> isArraySpecial(std::vector<int>& nums,
                                   std::vector<std::vector<int>>& queries) {
    return this->getSolution()(nums, queries);
  }
};

}  // namespace leetcode::problem_3152

#endif  // LEETCODE_PROBLEMS_SPECIAL_ARRAY_II_H__
