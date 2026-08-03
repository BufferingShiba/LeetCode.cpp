#ifndef LEETCODE_PROBLEMS_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H__
#define LEETCODE_PROBLEMS_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_26 {

using Func = std::function<int(std::vector<int>&)>;

class RemoveDuplicatesFromSortedArray
    : public SolutionBase<Func> {
 public:
  RemoveDuplicatesFromSortedArray();

  int removeDuplicates(std::vector<int>& nums);
};

}  // namespace leetcode::problem_26

#endif  // LEETCODE_PROBLEMS_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H__
