#ifndef LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_THREE_NUMBERS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_THREE_NUMBERS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_628 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumProductOfThreeNumbersSolution
    : public SolutionBase<Func> {
 public:
  MaximumProductOfThreeNumbersSolution();

  int maximumProduct(std::vector<int>& nums);
};

}  // namespace problem_628
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_THREE_NUMBERS_H__
