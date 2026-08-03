#ifndef LEETCODE_PROBLEMS_MAX_SUM_OF_A_PAIR_WITH_EQUAL_SUM_OF_DIGITS_H_
#define LEETCODE_PROBLEMS_MAX_SUM_OF_A_PAIR_WITH_EQUAL_SUM_OF_DIGITS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2342 {

using Func = std::function<int(std::vector<int>&)>;

class MaxSumOfAPairWithEqualSumOfDigitsSolution : public SolutionBase<Func> {
 public:
  MaxSumOfAPairWithEqualSumOfDigitsSolution();

  int maximumSum(std::vector<int>& nums);
};

}  // namespace problem_2342
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAX_SUM_OF_A_PAIR_WITH_EQUAL_SUM_OF_DIGITS_H_
