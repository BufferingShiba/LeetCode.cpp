#ifndef LEETCODE_PROBLEMS_MAKE_LEXICOGRAPHICALLY_SMALLEST_ARRAY_BY_SWAPPING_ELEMENTS_H
#define LEETCODE_PROBLEMS_MAKE_LEXICOGRAPHICALLY_SMALLEST_ARRAY_BY_SWAPPING_ELEMENTS_H

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2948 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class MakeLexicographicallySmallestArrayBySwappingElementsSolution
    : public SolutionBase<Func> {
 public:
  MakeLexicographicallySmallestArrayBySwappingElementsSolution();

  std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums,
                                                   int limit);
};

}  // namespace problem_2948
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAKE_LEXICOGRAPHICALLY_SMALLEST_ARRAY_BY_SWAPPING_ELEMENTS_H
