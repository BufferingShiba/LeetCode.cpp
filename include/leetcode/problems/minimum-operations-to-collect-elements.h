#ifndef LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_COLLECT_ELEMENTS_H__
#define LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_COLLECT_ELEMENTS_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2869 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumOperationsToCollectElementsSolution : public SolutionBase<Func> {
 public:
  MinimumOperationsToCollectElementsSolution();

  // Official method
  int minOperations(std::vector<int>& nums, int k);
};

}  // namespace problem_2869
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_COLLECT_ELEMENTS_H__
