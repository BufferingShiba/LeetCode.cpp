#ifndef LEETCODE_PROBLEM_1953_H__
#define LEETCODE_PROBLEM_1953_H__

#include "leetcode/core.h"

#include <vector>

namespace leetcode::problem_1953 {

using Func = std::function<long long(std::vector<int>&)>;

class MaximumNumberOfWeeksForWhichYouCanWorkSolution : public SolutionBase<Func> {
 public:
  MaximumNumberOfWeeksForWhichYouCanWorkSolution();

  long long numberOfWeeks(std::vector<int>& milestones);
};

}  // namespace leetcode::problem_1953

#endif  // LEETCODE_PROBLEM_1953_H__
