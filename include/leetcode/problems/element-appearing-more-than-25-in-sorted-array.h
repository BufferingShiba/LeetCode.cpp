#ifndef LEETCODE_PROBLEMS_ELEMENT_APPEARING_MORE_THAN_25_IN_SORTED_ARRAY_H
#define LEETCODE_PROBLEMS_ELEMENT_APPEARING_MORE_THAN_25_IN_SORTED_ARRAY_H

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1287 {

using Func = std::function<int(std::vector<int>&)>;

class ElementAppearingMoreThan25InSortedArraySolution
    : public SolutionBase<Func> {
 public:
  ElementAppearingMoreThan25InSortedArraySolution();

  int findSpecialInteger(std::vector<int>& arr);
};

}  // namespace problem_1287
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ELEMENT_APPEARING_MORE_THAN_25_IN_SORTED_ARRAY_H
