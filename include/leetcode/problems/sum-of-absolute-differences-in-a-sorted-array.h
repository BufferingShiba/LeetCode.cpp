#ifndef LEETCODE_PROBLEMS_1685_SUM_OF_ABSOLUTE_DIFFERENCES_IN_A_SORTED_ARRAY_H__
#define LEETCODE_PROBLEMS_1685_SUM_OF_ABSOLUTE_DIFFERENCES_IN_A_SORTED_ARRAY_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1685 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class SumOfAbsoluteDifferencesInASortedArraySolution
    : public SolutionBase<Func> {
 public:
  SumOfAbsoluteDifferencesInASortedArraySolution();

  std::vector<int> getSumAbsoluteDifferences(std::vector<int>& nums) {
    return getSolution()(nums);
  }
};

}  // namespace problem_1685
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_1685_SUM_OF_ABSOLUTE_DIFFERENCES_IN_A_SORTED_ARRAY_H__
