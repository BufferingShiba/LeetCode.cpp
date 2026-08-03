#ifndef LEETCODE_PROBLEM_1005_H_
#define LEETCODE_PROBLEM_1005_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1005 {

using Func = std::function<int(std::vector<int>&, int)>;

class MaximizeSumOfArrayAfterKNegationsSolution : public SolutionBase<Func> {
 public:
  MaximizeSumOfArrayAfterKNegationsSolution();

  int largestSumAfterKNegations(std::vector<int>& nums, int k);
};

}  // namespace problem_1005
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1005_H_
