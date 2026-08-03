#ifndef LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_SUBSEQUENCES_WITH_EQUAL_GCD_H__
#define LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_SUBSEQUENCES_WITH_EQUAL_GCD_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3336 {

using Func = std::function<int(std::vector<int>&)>;

class FindTheNumberOfSubsequencesWithEqualGcdSolution
    : public SolutionBase<Func> {
 public:
  FindTheNumberOfSubsequencesWithEqualGcdSolution();

  int subsequencePairCount(std::vector<int>& nums);
};

}  // namespace problem_3336
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_SUBSEQUENCES_WITH_EQUAL_GCD_H__
