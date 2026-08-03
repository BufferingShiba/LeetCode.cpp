#ifndef LEETCODE_CHECK_IF_ALL_THE_INTEGERS_IN_A_RANGE_ARE_COVERED_H
#define LEETCODE_CHECK_IF_ALL_THE_INTEGERS_IN_A_RANGE_ARE_COVERED_H

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1893 {

using Func = std::function<bool(std::vector<std::vector<int>>&, int, int)>;

class CheckIfAllTheIntegersInARangeAreCoveredSolution : public SolutionBase<Func> {
 public:
  CheckIfAllTheIntegersInARangeAreCoveredSolution();

  bool isCovered(std::vector<std::vector<int>>& ranges, int left, int right);
};

}  // namespace problem_1893
}  // namespace leetcode

#endif  // LEETCODE_CHECK_IF_ALL_THE_INTEGERS_IN_A_RANGE_ARE_COVERED_H
