#ifndef LEETCODE_PROBLEMS_MINIMUM_ARRAY_LENGTH_AFTER_PAIR_REMOVALS_H__
#define LEETCODE_PROBLEMS_MINIMUM_ARRAY_LENGTH_AFTER_PAIR_REMOVALS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2856 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumArrayLengthAfterPairRemovalsSolution
    : public SolutionBase<Func> {
 public:
  MinimumArrayLengthAfterPairRemovalsSolution();

  int minLengthAfterRemovals(std::vector<int>& nums);
};

}  // namespace leetcode::problem_2856

#endif  // LEETCODE_PROBLEMS_MINIMUM_ARRAY_LENGTH_AFTER_PAIR_REMOVALS_H__
