#ifndef LEETCODE_PROBLEMS_4SUM_H__
#define LEETCODE_PROBLEMS_4SUM_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_18 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<int>&, int)>;

class FourSumSolution : public SolutionBase<Func> {
 public:
  FourSumSolution();

  std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target);
};

}  // namespace problem_18
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_4SUM_H__
