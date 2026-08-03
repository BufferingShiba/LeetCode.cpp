#ifndef LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_TWO_INTEGERS_WITH_NO_COMMON_BITS_H_
#define LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_TWO_INTEGERS_WITH_NO_COMMON_BITS_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3670 {

using Func = std::function<long long(std::vector<int>&)>;

class MaximumProductOfTwoIntegersWithNoCommonBitsSolution
    : public SolutionBase<Func> {
 public:
  MaximumProductOfTwoIntegersWithNoCommonBitsSolution();

  long long maxProduct(std::vector<int>& nums);
};

}  // namespace problem_3670
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_TWO_INTEGERS_WITH_NO_COMMON_BITS_H_
