#ifndef LEETCODE_PROBLEM_3739_H_
#define LEETCODE_PROBLEM_3739_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3739 {

using Func = std::function<long long(std::vector<int>&, int)>;

class CountSubarraysWithMajorityElementIiSolution : public SolutionBase<Func> {
 public:
  CountSubarraysWithMajorityElementIiSolution();

  long long countMajoritySubarrays(std::vector<int>& nums, int target);
};

}  // namespace problem_3739
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_3739_H_
