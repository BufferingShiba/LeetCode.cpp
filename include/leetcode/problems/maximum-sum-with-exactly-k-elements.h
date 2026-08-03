#ifndef LEETCODE_PROBLEMS_MAXIMUM_SUM_WITH_EXACTLY_K_ELEMENTS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_SUM_WITH_EXACTLY_K_ELEMENTS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2656 {

using Func = std::function<int(std::vector<int>&, int)>;

class MaximumSumWithExactlyKElementsSolution
    : public SolutionBase<Func> {
 public:
  MaximumSumWithExactlyKElementsSolution();

  int maximizeSum(std::vector<int>& nums, int k);
};

}  // namespace problem_2656
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_SUM_WITH_EXACTLY_K_ELEMENTS_H__
