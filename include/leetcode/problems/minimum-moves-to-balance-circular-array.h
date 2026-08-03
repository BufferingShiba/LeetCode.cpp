#ifndef LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_BALANCE_CIRCULAR_ARRAY_H_
#define LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_BALANCE_CIRCULAR_ARRAY_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3776 {

using Func = std::function<long long(std::vector<int>&)>;

class MinimumMovesToBalanceCircularArraySolution : public SolutionBase<Func> {
 public:
  MinimumMovesToBalanceCircularArraySolution();

  long long minMoves(std::vector<int>& balance);
};

}  // namespace problem_3776
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_BALANCE_CIRCULAR_ARRAY_H_
