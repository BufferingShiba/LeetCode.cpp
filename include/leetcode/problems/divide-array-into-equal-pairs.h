#ifndef LEETCODE_PROBLEMS_DIVIDE_ARRAY_INTO_EQUAL_PAIRS_H__
#define LEETCODE_PROBLEMS_DIVIDE_ARRAY_INTO_EQUAL_PAIRS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2206 {

using Func = std::function<bool(std::vector<int>&)>;

class DivideArrayIntoEqualPairsSolution
    : public SolutionBase<Func> {
 public:
  DivideArrayIntoEqualPairsSolution();

  bool divideArray(std::vector<int>& nums);
};

}  // namespace leetcode::problem_2206

#endif  // LEETCODE_PROBLEMS_DIVIDE_ARRAY_INTO_EQUAL_PAIRS_H__
