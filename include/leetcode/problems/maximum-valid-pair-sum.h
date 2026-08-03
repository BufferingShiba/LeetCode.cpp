#ifndef LEETCODE_PROBLEMS_3979_MAXIMUM_VALID_PAIR_SUM_H_
#define LEETCODE_PROBLEMS_3979_MAXIMUM_VALID_PAIR_SUM_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3979 {

using Func = std::function<int(std::vector<int>&, int)>;

class MaximumValidPairSumSolution : public SolutionBase<Func> {
 public:
  MaximumValidPairSumSolution();

  int maxValidPairSum(std::vector<int>& nums, int k) {
    return getSolution()(nums, k);
  }
};

}  // namespace problem_3979
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_3979_MAXIMUM_VALID_PAIR_SUM_H_
