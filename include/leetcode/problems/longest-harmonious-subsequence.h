#ifndef LEETCODE_PROBLEMS_LONGEST_HARMONIOUS_SUBSEQUENCE_H__
#define LEETCODE_PROBLEMS_LONGEST_HARMONIOUS_SUBSEQUENCE_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_594 {

using Func = std::function<int(std::vector<int>&)>;

class LongestHarmoniousSubsequenceSolution
    : public SolutionBase<Func> {
 public:
  LongestHarmoniousSubsequenceSolution();

  int findLHS(std::vector<int>& nums);
};

}  // namespace problem_594
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_HARMONIOUS_SUBSEQUENCE_H__
