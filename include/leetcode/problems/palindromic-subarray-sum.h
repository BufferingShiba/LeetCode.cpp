#ifndef LEETCODE_PROBLEMS_PALINDROMIC_SUBARRAY_SUM_H__
#define LEETCODE_PROBLEMS_PALINDROMIC_SUBARRAY_SUM_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3985 {

using Func = std::function<long long(std::vector<int>&)>;

class PalindromicSubarraySumSolution : public SolutionBase<Func> {
 public:
  PalindromicSubarraySumSolution();

  long long getSum(std::vector<int>& nums);
};

}  // namespace problem_3985
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PALINDROMIC_SUBARRAY_SUM_H__
