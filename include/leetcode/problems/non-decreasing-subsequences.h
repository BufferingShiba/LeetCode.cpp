#ifndef LEETCODE_PROBLEMS_NON_DECREASING_SUBSEQUENCES_H__
#define LEETCODE_PROBLEMS_NON_DECREASING_SUBSEQUENCES_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_491 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<int>&)>;

class NonDecreasingSubsequencesSolution
    : public SolutionBase<Func> {
 public:
  NonDecreasingSubsequencesSolution();

  std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums);
};

}  // namespace leetcode::problem_491

#endif  // LEETCODE_PROBLEMS_NON_DECREASING_SUBSEQUENCES_H__
