#ifndef LEETCODE_PROBLEMS_FIND_MINIMUM_LOG_TRANSPORTATION_COST_H__
#define LEETCODE_PROBLEMS_FIND_MINIMUM_LOG_TRANSPORTATION_COST_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode {
namespace problem_3560 {

using Func = std::function<long long(int, int, int)>;

class FindMinimumLogTransportationCostSolution
    : public SolutionBase<Func> {
 public:
  FindMinimumLogTransportationCostSolution();
  long long minCuttingCost(int n, int m, int k);
};

}  // namespace problem_3560
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_MINIMUM_LOG_TRANSPORTATION_COST_H__
