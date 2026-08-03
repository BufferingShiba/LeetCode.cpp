#ifndef LEETCODE_PROBLEMS_3SUM_H_
#define LEETCODE_PROBLEMS_3SUM_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_15 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<int>&)>;

class ThreeSumSolution : public SolutionBase<Func> {
 public:
  ThreeSumSolution();

  std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
};

}  // namespace problem_15
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_3SUM_H_
