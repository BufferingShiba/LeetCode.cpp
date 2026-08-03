#ifndef LEETCODE_PROBLEMS_MINIMUM_COST_TO_PARTITION_A_BINARY_STRING_H__
#define LEETCODE_PROBLEMS_MINIMUM_COST_TO_PARTITION_A_BINARY_STRING_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_3864 {

using Func = std::function<long long(std::string, int, int)>;

class MinimumCostToPartitionABinaryStringSolution
    : public SolutionBase<Func> {
 public:
  MinimumCostToPartitionABinaryStringSolution();

  long long minCost(std::string s, int encCost, int flatCost) {
    return getSolution()(s, encCost, flatCost);
  }
};

}  // namespace problem_3864
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_COST_TO_PARTITION_A_BINARY_STRING_H__
