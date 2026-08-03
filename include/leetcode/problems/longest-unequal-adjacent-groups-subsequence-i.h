#ifndef LEETCODE_PROBLEMS_LONGEST_UNEQUAL_ADJACENT_GROUPS_SUBSEQUENCE_I_H__
#define LEETCODE_PROBLEMS_LONGEST_UNEQUAL_ADJACENT_GROUPS_SUBSEQUENCE_I_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2900 {

using Func = std::function<std::vector<std::string>(std::vector<std::string>&,
                                                    std::vector<int>&)>;

class LongestUnequalAdjacentGroupsSubsequenceISolution
    : public SolutionBase<Func> {
 public:
  LongestUnequalAdjacentGroupsSubsequenceISolution();

  std::vector<std::string> getLongestSubsequence(
      std::vector<std::string>& words, std::vector<int>& groups);
};

}  // namespace problem_2900
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_UNEQUAL_ADJACENT_GROUPS_SUBSEQUENCE_I_H__
