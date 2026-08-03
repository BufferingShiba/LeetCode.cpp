#ifndef LEETCODE_PROBLEMS_MINIMUM_COST_TO_BUY_APPLES_II_H__
#define LEETCODE_PROBLEMS_MINIMUM_COST_TO_BUY_APPLES_II_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3928 {

using Func = std::function<std::vector<int>(
    int, std::vector<int>&, std::vector<std::vector<int>>&)>;

class MinimumCostToBuyApplesIISolution : public SolutionBase<Func> {
 public:
  MinimumCostToBuyApplesIISolution();
};

}  // namespace problem_3928
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_COST_TO_BUY_APPLES_II_H__
