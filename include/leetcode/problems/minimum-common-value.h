#ifndef LEETCODE_PROBLEMS_MINIMUM_COMMON_VALUE_H__
#define LEETCODE_PROBLEMS_MINIMUM_COMMON_VALUE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2540 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class MinimumCommonValueSolution : public SolutionBase<Func> {
 public:
  MinimumCommonValueSolution();
  int getCommon(std::vector<int>& nums1, std::vector<int>& nums2);
};

}  // namespace problem_2540
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_COMMON_VALUE_H__
