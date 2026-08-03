#ifndef LEETCODE_PROBLEM_3116_H_
#define LEETCODE_PROBLEM_3116_H_

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3116 {

using Func = std::function<long long(std::vector<int>&, int)>;

class KthSmallestAmountWithSingleDenominationCombinationSolution : public SolutionBase<Func> {
 public:
  KthSmallestAmountWithSingleDenominationCombinationSolution();

  long long findKthSmallest(std::vector<int>& coins, int k);
};

} // namespace problem_3116
} // namespace leetcode

#endif
