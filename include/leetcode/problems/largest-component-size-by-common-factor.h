#ifndef LEETCODE_PROBLEMS_LARGEST_COMPONENT_SIZE_BY_COMMON_FACTOR_H__
#define LEETCODE_PROBLEMS_LARGEST_COMPONENT_SIZE_BY_COMMON_FACTOR_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_952 {

using Func = std::function<int(std::vector<int>&)>;

class LargestComponentSizeByCommonFactorSolution
    : public SolutionBase<Func> {
 public:
  LargestComponentSizeByCommonFactorSolution();

  int largestComponentSize(std::vector<int>& nums);
};

}  // namespace problem_952
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LARGEST_COMPONENT_SIZE_BY_COMMON_FACTOR_H__
