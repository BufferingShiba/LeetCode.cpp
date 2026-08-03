#ifndef LEETCODE_PROBLEMS_MINIMUM_COST_TO_MAKE_ARRAY_EQUALINDROMIC_H_
#define LEETCODE_PROBLEMS_MINIMUM_COST_TO_MAKE_ARRAY_EQUALINDROMIC_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2967 {

using Func = std::function<long long(std::vector<int>&)>;

class MinimumCostToMakeArrayEqualindromicSolution
    : public SolutionBase<Func> {
 public:
  MinimumCostToMakeArrayEqualindromicSolution();

  long long minimumCost(std::vector<int>& nums);
};

}  // namespace problem_2967
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_COST_TO_MAKE_ARRAY_EQUALINDROMIC_H_
