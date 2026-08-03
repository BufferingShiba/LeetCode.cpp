#ifndef LEETCODE_PROBLEMS_LONGEST_SUBSEQUENCE_WITH_LIMITED_SUM_H__
#define LEETCODE_PROBLEMS_LONGEST_SUBSEQUENCE_WITH_LIMITED_SUM_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2389 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<int>&)>;

class LongestSubsequenceWithLimitedSumSolution
    : public SolutionBase<Func> {
 public:
  LongestSubsequenceWithLimitedSumSolution();

  std::vector<int> answerQueries(std::vector<int>& nums,
                                 std::vector<int>& queries);
};

}  // namespace problem_2389
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_SUBSEQUENCE_WITH_LIMITED_SUM_H__
