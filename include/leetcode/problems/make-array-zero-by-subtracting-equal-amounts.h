#ifndef LEETCODE_PROBLEMS_MAKE_ARRAY_ZERO_BY_SUBTRACTING_EQUAL_AMOUNTS_H__
#define LEETCODE_PROBLEMS_MAKE_ARRAY_ZERO_BY_SUBTRACTING_EQUAL_AMOUNTS_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2357 {

using Func = std::function<int(std::vector<int>&)>;

class MakeArrayZeroBySubtractingEqualAmountsSolution
    : public SolutionBase<Func> {
 public:
  MakeArrayZeroBySubtractingEqualAmountsSolution();
  int minimumOperations(std::vector<int>& nums);
};

}  // namespace problem_2357
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAKE_ARRAY_ZERO_BY_SUBTRACTING_EQUAL_AMOUNTS_H__
