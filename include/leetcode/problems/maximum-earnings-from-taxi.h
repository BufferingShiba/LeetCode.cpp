#ifndef LEETCODE_PROBLEMS_MAXIMUM_EARNINGS_FROM_TAXI_H_
#define LEETCODE_PROBLEMS_MAXIMUM_EARNINGS_FROM_TAXI_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2008 {

using Func = std::function<long long(int, std::vector<std::vector<int>>&)>;

class MaximumEarningsFromTaxiSolution : public SolutionBase<Func> {
 public:
  MaximumEarningsFromTaxiSolution();
};

}  // namespace problem_2008
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_EARNINGS_FROM_TAXI_H_
