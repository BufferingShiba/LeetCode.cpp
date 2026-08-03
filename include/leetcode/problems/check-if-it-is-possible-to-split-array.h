#ifndef LEETCODE_PROBLEMS_CHECK_IF_IT_IS_POSSIBLE_TO_SPLIT_ARRAY_H__
#define LEETCODE_PROBLEMS_CHECK_IF_IT_IS_POSSIBLE_TO_SPLIT_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2811 {

using Func = std::function<bool(std::vector<int>&, int)>;

class CheckIfItIsPossibleToSplitArraySolution : public SolutionBase<Func> {
 public:
  CheckIfItIsPossibleToSplitArraySolution();

  bool canSplitArray(std::vector<int>& nums, int m);
};

}  // namespace problem_2811
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_IT_IS_POSSIBLE_TO_SPLIT_ARRAY_H__
