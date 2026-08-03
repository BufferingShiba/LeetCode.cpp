#ifndef LEETCODE_PROBLEMS_FIND_SUBSEQUENCE_OF_LENGTH_K_WITH_THE_LARGEST_SUM_H_
#define LEETCODE_PROBLEMS_FIND_SUBSEQUENCE_OF_LENGTH_K_WITH_THE_LARGEST_SUM_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2099 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class FindSubsequenceOfLengthKWithTheLargestSumSolution
    : public SolutionBase<Func> {
 public:
  FindSubsequenceOfLengthKWithTheLargestSumSolution();

  std::vector<int> maxSubsequence(std::vector<int>& nums, int k);
};

}  // namespace problem_2099
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_SUBSEQUENCE_OF_LENGTH_K_WITH_THE_LARGEST_SUM_H_
