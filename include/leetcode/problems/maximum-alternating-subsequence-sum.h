#ifndef LEETCODE_PROBLEMS_MAXIMUM_ALTERNATING_SUBSEQUENCE_SUM_H_
#define LEETCODE_PROBLEMS_MAXIMUM_ALTERNATING_SUBSEQUENCE_SUM_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1911 {

using Func = std::function<long long(std::vector<int>&)>;

class MaximumAlternatingSubsequenceSumSolution : public SolutionBase<Func> {
 public:
  MaximumAlternatingSubsequenceSumSolution();

  long long maxAlternatingSum(std::vector<int>& nums);
};

}  // namespace problem_1911
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_ALTERNATING_SUBSEQUENCE_SUM_H_
