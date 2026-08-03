#ifndef LEETCODE_PROBLEMS_FIND_COMMON_ELEMENTS_BETWEEN_TWO_ARRAYS_H_
#define LEETCODE_PROBLEMS_FIND_COMMON_ELEMENTS_BETWEEN_TWO_ARRAYS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2956 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<int>&)>;

class FindCommonElementsBetweenTwoArraysSolution : public SolutionBase<Func> {
 public:
  FindCommonElementsBetweenTwoArraysSolution();

  std::vector<int> findIntersectionValues(std::vector<int>& nums1,
                                          std::vector<int>& nums2);
};

}  // namespace problem_2956
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_COMMON_ELEMENTS_BETWEEN_TWO_ARRAYS_H_
