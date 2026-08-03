#ifndef LEETCODE_PROBLEMS_MAXIMUM_SUBARRAY_WITH_EQUAL_PRODUCTS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_SUBARRAY_WITH_EQUAL_PRODUCTS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3411 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumSubarrayWithEqualProductsSolution : public SolutionBase<Func> {
 public:
  MaximumSubarrayWithEqualProductsSolution();
  int maxLength(std::vector<int>& nums);
};

}  // namespace problem_3411
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_SUBARRAY_WITH_EQUAL_PRODUCTS_H__
