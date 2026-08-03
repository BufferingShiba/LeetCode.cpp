#ifndef LEETCODE_PROBLEMS_2261_K_DIVISIBLE_ELEMENTS_SUBARRAYS_H_
#define LEETCODE_PROBLEMS_2261_K_DIVISIBLE_ELEMENTS_SUBARRAYS_H_

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2261 {

using Func = std::function<int(std::vector<int>&, int, int)>;

class KDivisibleElementsSubarraysSolution
    : public SolutionBase<Func> {
 public:
  int countDistinct(std::vector<int>& nums, int k, int p);
  KDivisibleElementsSubarraysSolution();
};

}  // namespace problem_2261
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_2261_K_DIVISIBLE_ELEMENTS_SUBARRAYS_H_
