#ifndef LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAXIMIZE_LAST_ELEMENTS_IN_ARRAYS_H_
#define LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAXIMIZE_LAST_ELEMENTS_IN_ARRAYS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2934 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class MinimumOperationsToMaximizeLastElementsInArraysSolution
    : public SolutionBase<Func> {
 public:
  MinimumOperationsToMaximizeLastElementsInArraysSolution();
  int minOperations(std::vector<int>& nums1, std::vector<int>& nums2);
};

}  // namespace problem_2934
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAXIMIZE_LAST_ELEMENTS_IN_ARRAYS_H_
