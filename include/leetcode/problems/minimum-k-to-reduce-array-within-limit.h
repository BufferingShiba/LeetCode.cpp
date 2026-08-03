#ifndef LEETCODE_PROBLEMS_MINIMUM_K_TO_REDUCE_ARRAY_WITHIN_LIMIT_H_
#define LEETCODE_PROBLEMS_MINIMUM_K_TO_REDUCE_ARRAY_WITHIN_LIMIT_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3824 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumKToReduceArrayWithinLimitSolution : public SolutionBase<Func> {
 public:
  MinimumKToReduceArrayWithinLimitSolution();

  int minimumK(std::vector<int>& nums);
};

}  // namespace problem_3824
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_K_TO_REDUCE_ARRAY_WITHIN_LIMIT_H_
