#ifndef LEETCODE_PROBLEMS_FIND_MAXIMUM_NON_DECREASING_ARRAY_LENGTH_H_
#define LEETCODE_PROBLEMS_FIND_MAXIMUM_NON_DECREASING_ARRAY_LENGTH_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2945 {

using Func = std::function<int(std::vector<int>&)>;

class FindMaximumNonDecreasingArrayLengthSolution : public SolutionBase<Func> {
 public:
  FindMaximumNonDecreasingArrayLengthSolution();
  int findMaximumLength(std::vector<int>& nums);
};

}  // namespace problem_2945
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_MAXIMUM_NON_DECREASING_ARRAY_LENGTH_H_
