#ifndef LEETCODE_PROBLEMS_FINAL_ARRAY_STATE_AFTER_K_MULTIPLICATION_OPERATIONS_II_H_
#define LEETCODE_PROBLEMS_FINAL_ARRAY_STATE_AFTER_K_MULTIPLICATION_OPERATIONS_II_H_

#include <functional>
#include <vector>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_3266 {

using Func = std::function<std::vector<int>(std::vector<int>&, int, int)>;

class FinalArrayStateAfterKMultiplicationOperationsIiSolution : public SolutionBase<Func> {
 public:
  FinalArrayStateAfterKMultiplicationOperationsIiSolution();

  std::vector<int> getFinalState(std::vector<int>& nums, int k, int multiplier);
};

}  // namespace problem_3266
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FINAL_ARRAY_STATE_AFTER_K_MULTIPLICATION_OPERATIONS_II_H_
