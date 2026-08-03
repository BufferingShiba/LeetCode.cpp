#ifndef LEETCODE_PROBLEMS_CONTAINS_DUPLICATE_III_H_
#define LEETCODE_PROBLEMS_CONTAINS_DUPLICATE_III_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_220 {

using Func = std::function<bool(std::vector<int>&, int, int)>;

class ContainsDuplicateIiiSolution : public SolutionBase<Func> {
 public:
  ContainsDuplicateIiiSolution();

  bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff,
                                      int valueDiff);
};

}  // namespace problem_220
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CONTAINS_DUPLICATE_III_H_
