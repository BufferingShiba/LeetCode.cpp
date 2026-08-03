#ifndef LEETCODE_PROBLEMS_SLIDING_WINDOW_MAXIMUM_H_
#define LEETCODE_PROBLEMS_SLIDING_WINDOW_MAXIMUM_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_239 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class SlidingWindowMaximumSolution : public SolutionBase<Func> {
 public:
  SlidingWindowMaximumSolution();

  std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k);
};

}  // namespace problem_239
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SLIDING_WINDOW_MAXIMUM_H_
