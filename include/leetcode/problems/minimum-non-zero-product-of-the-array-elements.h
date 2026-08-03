#ifndef LEETCODE_PROBLEMS_MINIMUM_NON_ZERO_PRODUCT_OF_THE_ARRAY_ELEMENTS_H__
#define LEETCODE_PROBLEMS_MINIMUM_NON_ZERO_PRODUCT_OF_THE_ARRAY_ELEMENTS_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1969 {

using Func = std::function<int(int)>;

class MinimumNonZeroProductOfTheArrayElementsSolution
    : public SolutionBase<Func> {
 public:
  MinimumNonZeroProductOfTheArrayElementsSolution();

  int minNonZeroProduct(int p) { return getSolution()(p); }
};

}  // namespace problem_1969
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_NON_ZERO_PRODUCT_OF_THE_ARRAY_ELEMENTS_H__
