#ifndef LEETCODE_PROBLEMS_REVERSE_SUBARRAY_TO_MAXIMIZE_ARRAY_VALUE_H__
#define LEETCODE_PROBLEMS_REVERSE_SUBARRAY_TO_MAXIMIZE_ARRAY_VALUE_H__

#include "leetcode/core.h"

#include <cstdint>
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1330 {

using Func = std::function<int(std::vector<int>&)>;

class ReverseSubarrayToMaximizeArrayValueSolution
    : public SolutionBase<Func> {
 public:
  ReverseSubarrayToMaximizeArrayValueSolution();

  int maxValueAfterReverse(std::vector<int>& nums);
};

}  // namespace problem_1330
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REVERSE_SUBARRAY_TO_MAXIMIZE_ARRAY_VALUE_H__
