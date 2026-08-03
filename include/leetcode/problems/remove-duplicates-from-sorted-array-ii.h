#ifndef LEETCODE_PROBLEMS_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H__
#define LEETCODE_PROBLEMS_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_80 {

using Func = std::function<int(std::vector<int>&)>;

class RemoveDuplicatesFromSortedArrayIiSolution
    : public SolutionBase<Func> {
 public:
  RemoveDuplicatesFromSortedArrayIiSolution();

  int removeDuplicates(std::vector<int>& nums);
};

}  // namespace problem_80
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H__
