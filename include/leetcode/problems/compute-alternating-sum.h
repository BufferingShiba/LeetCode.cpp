#ifndef LEETCODE_PROBLEMS_COMPUTE_ALTERNATING_SUM_H_
#define LEETCODE_PROBLEMS_COMPUTE_ALTERNATING_SUM_H_

#include <functional>
#include <vector>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_3701 {

using Func = std::function<int(std::vector<int>&)>;

class ComputeAlternatingSumSolution : public SolutionBase<Func> {
 public:
  ComputeAlternatingSumSolution();

  int alternatingSum(std::vector<int>& nums);
};

}  // namespace problem_3701
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COMPUTE_ALTERNATING_SUM_H_
