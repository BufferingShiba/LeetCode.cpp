#ifndef LEETCODE_PROBLEMS_RANGE_PRODUCT_QUERIES_OF_POWERS_H__
#define LEETCODE_PROBLEMS_RANGE_PRODUCT_QUERIES_OF_POWERS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2438 {

using Func = std::function<std::vector<int>(int, std::vector<std::vector<int>>&)>;

class RangeProductQueriesOfPowersSolution
    : public SolutionBase<Func> {
 public:
  RangeProductQueriesOfPowersSolution();

  std::vector<int> productQueries(int n, std::vector<std::vector<int>>& queries);
};

}  // namespace problem_2438
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_RANGE_PRODUCT_QUERIES_OF_POWERS_H__
