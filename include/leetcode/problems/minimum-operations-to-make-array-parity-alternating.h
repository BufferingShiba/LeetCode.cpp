#ifndef LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_ARRAY_PARITY_ALTERNATING_H__
#define LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_ARRAY_PARITY_ALTERNATING_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3854 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class MinimumOperationsToMakeArrayParityAlternatingSolution
    : public SolutionBase<Func> {
 public:
  MinimumOperationsToMakeArrayParityAlternatingSolution();

  std::vector<int> makeParityAlternating(std::vector<int>& nums);
};

}  // namespace problem_3854
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_ARRAY_PARITY_ALTERNATING_H__
