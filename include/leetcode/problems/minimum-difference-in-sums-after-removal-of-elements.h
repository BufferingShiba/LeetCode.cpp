#ifndef LEETCODE_PROBLEMS_MINIMUM_DIFFERENCE_IN_SUMS_AFTER_REMOVAL_OF_ELEMENTS_H__
#define LEETCODE_PROBLEMS_MINIMUM_DIFFERENCE_IN_SUMS_AFTER_REMOVAL_OF_ELEMENTS_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2163 {

using Func =
    std::function<long long(std::vector<int>&)>;

class MinimumDifferenceInSumsAfterRemovalOfElementsSolution
    : public SolutionBase<Func> {
 public:
  MinimumDifferenceInSumsAfterRemovalOfElementsSolution();

  long long minimumDifference(std::vector<int>& nums);
};

}  // namespace problem_2163
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_DIFFERENCE_IN_SUMS_AFTER_REMOVAL_OF_ELEMENTS_H__
