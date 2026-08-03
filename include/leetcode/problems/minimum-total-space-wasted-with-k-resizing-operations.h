#ifndef LEETCODE_PROBLEMS_MINIMUM_TOTAL_SPACE_WASTED_WITH_K_RESIZING_OPERATIONS_H_
#define LEETCODE_PROBLEMS_MINIMUM_TOTAL_SPACE_WASTED_WITH_K_RESIZING_OPERATIONS_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1959 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumTotalSpaceWastedWithKResizingOperationsSolution
    : public SolutionBase<Func> {
 public:
  MinimumTotalSpaceWastedWithKResizingOperationsSolution();

  int minSpaceWastedKResizing(std::vector<int>& nums, int k);
};

}  // namespace problem_1959
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_TOTAL_SPACE_WASTED_WITH_K_RESIZING_OPERATIONS_H_
