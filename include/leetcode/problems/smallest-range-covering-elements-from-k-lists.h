#ifndef LEETCODE_PROBLEMS_SMALLEST_RANGE_COVERING_ELEMENTS_FROM_K_LISTS_H_
#define LEETCODE_PROBLEMS_SMALLEST_RANGE_COVERING_ELEMENTS_FROM_K_LISTS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_632 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&)>;

class SmallestRangeCoveringElementsFromKListsSolution : public SolutionBase<Func> {
 public:
  SmallestRangeCoveringElementsFromKListsSolution();
  std::vector<int> smallestRange(std::vector<std::vector<int>>& nums);
};

}  // namespace problem_632
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SMALLEST_RANGE_COVERING_ELEMENTS_FROM_K_LISTS_H_
