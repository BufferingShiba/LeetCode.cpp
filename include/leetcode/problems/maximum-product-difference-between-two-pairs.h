#ifndef LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_DIFFERENCE_BETWEEN_TWO_PAIRS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_DIFFERENCE_BETWEEN_TWO_PAIRS_H__

#include <vector>
#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1913 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumProductDifferenceBetweenTwoPairsSolution
    : public SolutionBase<Func> {
 public:
  MaximumProductDifferenceBetweenTwoPairsSolution();

  int maxProductDifference(std::vector<int>& nums);
};

}  // namespace problem_1913
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_DIFFERENCE_BETWEEN_TWO_PAIRS_H__
