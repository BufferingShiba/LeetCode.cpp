#ifndef LEETCODE_PROBLEMS_ARITHMETIC_SLICES_H__
#define LEETCODE_PROBLEMS_ARITHMETIC_SLICES_H__

#include <functional>
#include <vector>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_413 {

using Func = std::function<int(std::vector<int>&)>;

class ArithmeticSlicesSolution : public SolutionBase<Func> {
 public:
  ArithmeticSlicesSolution();

  int numberOfArithmeticSlices(std::vector<int>& nums);
};

}  // namespace problem_413
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ARITHMETIC_SLICES_H__
