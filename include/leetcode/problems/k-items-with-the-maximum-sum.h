#ifndef LEETCODE_PROBLEMS_K_ITEMS_WITH_THE_MAXIMUM_SUM_H__
#define LEETCODE_PROBLEMS_K_ITEMS_WITH_THE_MAXIMUM_SUM_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2600 {

using Func = std::function<int(int, int, int, int)>;

class KItemsWithTheMaximumSumSolution
    : public SolutionBase<Func> {
 public:
  KItemsWithTheMaximumSumSolution();

  int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k);
};

}  // namespace problem_2600
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_K_ITEMS_WITH_THE_MAXIMUM_SUM_H__
