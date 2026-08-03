#ifndef LEETCODE_PROBLEMS_SEARCH_IN_ROTATED_SORTED_ARRAY_II_H__
#define LEETCODE_PROBLEMS_SEARCH_IN_ROTATED_SORTED_ARRAY_II_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_81 {

using Func = std::function<bool(std::vector<int>&, int)>;

class SearchInRotatedSortedArrayIiSolution
    : public SolutionBase<Func> {
 public:
  SearchInRotatedSortedArrayIiSolution();

  bool search(std::vector<int>& nums, int target);
};

}  // namespace problem_81
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SEARCH_IN_ROTATED_SORTED_ARRAY_II_H__
