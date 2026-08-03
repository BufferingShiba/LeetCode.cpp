#ifndef LEETCODE_PROBLEMS_SPLIT_ARRAY_INTO_CONSECUTIVE_SUBSEQUENCES_H__
#define LEETCODE_PROBLEMS_SPLIT_ARRAY_INTO_CONSECUTIVE_SUBSEQUENCES_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode {
namespace problem_659 {

using Func = std::function<bool(std::vector<int>&)>;

class SplitArrayIntoConsecutiveSubsequencesSolution
    : public SolutionBase<Func> {
 public:
  SplitArrayIntoConsecutiveSubsequencesSolution();

  bool isPossible(std::vector<int>& nums);
};

}  // namespace problem_659
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SPLIT_ARRAY_INTO_CONSECUTIVE_SUBSEQUENCES_H__
