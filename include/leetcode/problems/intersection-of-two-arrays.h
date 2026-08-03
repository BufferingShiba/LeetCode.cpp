#ifndef LEETCODE_PROBLEMS_INTERSECTION_OF_TWO_ARRAYS_H__
#define LEETCODE_PROBLEMS_INTERSECTION_OF_TWO_ARRAYS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_349 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<int>&)>;

class IntersectionOfTwoArraysSolution : public SolutionBase<Func> {
 public:
  IntersectionOfTwoArraysSolution();

  std::vector<int> intersection(std::vector<int>& nums1,
                                std::vector<int>& nums2);
};

}  // namespace problem_349
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_INTERSECTION_OF_TWO_ARRAYS_H__
