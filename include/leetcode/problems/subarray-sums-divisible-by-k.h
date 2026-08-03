#ifndef LEETCODE_PROBLEMS_SUBARRAY_SUMS_DIVISIBLE_BY_K_H_
#define LEETCODE_PROBLEMS_SUBARRAY_SUMS_DIVISIBLE_BY_K_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_974 {

using Func = std::function<int(std::vector<int>&, int)>;

class SubarraySumsDivisibleByKSolution : public SolutionBase<Func> {
 public:
  SubarraySumsDivisibleByKSolution();

  int subarraysDivByK(std::vector<int>& nums, int k);
};

}  // namespace problem_974
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUBARRAY_SUMS_DIVISIBLE_BY_K_H_
