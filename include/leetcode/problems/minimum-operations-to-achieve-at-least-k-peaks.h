#ifndef LEETCODE_PROBLEM_3892_H_
#define LEETCODE_PROBLEM_3892_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3892 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumOperationsToAchieveAtLeastKPeaksSolution : public SolutionBase<Func> {
 public:
  MinimumOperationsToAchieveAtLeastKPeaksSolution();
  int minOperations(std::vector<int>& nums, int k);
};

}  // namespace problem_3892
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_3892_H_
