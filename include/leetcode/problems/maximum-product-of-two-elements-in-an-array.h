#ifndef LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_TWO_ELEMENTS_IN_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_TWO_ELEMENTS_IN_AN_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1464 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumProductOfTwoElementsInAnArray
    : public SolutionBase<Func> {
 public:
  MaximumProductOfTwoElementsInAnArray();

  int maxProduct(std::vector<int>& nums);
};

}  // namespace problem_1464
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_TWO_ELEMENTS_IN_AN_ARRAY_H__
