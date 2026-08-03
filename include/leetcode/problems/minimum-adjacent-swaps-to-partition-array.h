#ifndef LEETCODE_PROBLEMS_MINIMUM_ADJACENT_SWAPS_TO_PARTITION_ARRAY_H__
#define LEETCODE_PROBLEMS_MINIMUM_ADJACENT_SWAPS_TO_PARTITION_ARRAY_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3994 {

using Func = std::function<int(std::vector<int>&, int, int)>;

class MinimumAdjacentSwapsToPartitionArraySolution
    : public SolutionBase<Func> {
 public:
  MinimumAdjacentSwapsToPartitionArraySolution();

  int minAdjacentSwaps(std::vector<int>& nums, int a, int b);
};

}  // namespace problem_3994
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_ADJACENT_SWAPS_TO_PARTITION_ARRAY_H__
