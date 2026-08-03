#ifndef LEETCODE_PROBLEMS_MINIMUM_SPACE_WASTED_FROM_PACKAGING_H__
#define LEETCODE_PROBLEMS_MINIMUM_SPACE_WASTED_FROM_PACKAGING_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1889 {

using Func = std::function<int(std::vector<int>&, std::vector<std::vector<int>>&)>;

class MinimumSpaceWastedFromPackagingSolution
    : public SolutionBase<Func> {
 public:
  MinimumSpaceWastedFromPackagingSolution();

  int minWastedSpace(std::vector<int>& packages,
                     std::vector<std::vector<int>>& boxes);
};

}  // namespace problem_1889
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_SPACE_WASTED_FROM_PACKAGING_H__
