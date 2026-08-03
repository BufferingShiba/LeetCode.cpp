#ifndef LEETCODE_PROBLEMS_FIND_THE_MAXIMUM_LENGTH_OF_VALID_SUBSEQUENCE_II_H__
#define LEETCODE_PROBLEMS_FIND_THE_MAXIMUM_LENGTH_OF_VALID_SUBSEQUENCE_II_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3202 {

using Func = std::function<int(std::vector<int>&, int)>;

class FindTheMaximumLengthOfValidSubsequenceIiSolution
    : public SolutionBase<Func> {
 public:
  FindTheMaximumLengthOfValidSubsequenceIiSolution();

  int maximumLength(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_3202

#endif  // LEETCODE_PROBLEMS_FIND_THE_MAXIMUM_LENGTH_OF_VALID_SUBSEQUENCE_II_H__
