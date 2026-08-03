#ifndef LEETCODE_PROBLEMS_FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY_II_H__
#define LEETCODE_PROBLEMS_FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY_II_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_154 {

using Func = std::function<int(std::vector<int>&)>;

class FindMinimumInRotatedSortedArrayIiSolution
    : public SolutionBase<Func> {
public:
  FindMinimumInRotatedSortedArrayIiSolution();

  int findMin(std::vector<int>& nums);
};

}  // namespace problem_154
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY_II_H__
