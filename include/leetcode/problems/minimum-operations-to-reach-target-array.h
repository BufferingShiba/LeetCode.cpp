#ifndef LEETCODE_PROBLEM_3810_H
#define LEETCODE_PROBLEM_3810_H

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3810 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class MinimumOperationsToReachTargetArraySolution : public SolutionBase<Func> {
 public:
  MinimumOperationsToReachTargetArraySolution();
  int minOperations(std::vector<int>& nums, std::vector<int>& target);
};

}  // namespace problem_3810
}  // namespace leetcode

#endif
