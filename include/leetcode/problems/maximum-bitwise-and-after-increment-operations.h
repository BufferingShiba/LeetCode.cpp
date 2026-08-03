#ifndef LEETCODE_PROBLEMS_MAXIMUM_BITWISE_AND_AFTER_INCREMENT_OPERATIONS_H_
#define LEETCODE_PROBLEMS_MAXIMUM_BITWISE_AND_AFTER_INCREMENT_OPERATIONS_H_

#include "leetcode/core.h"

#include <cstdint>
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3806 {

using Func = std::function<int(std::vector<int>&, int, int)>;

class MaximumBitwiseAndAfterIncrementOperationsSolution
    : public SolutionBase<Func> {
 public:
  MaximumBitwiseAndAfterIncrementOperationsSolution();

  int maximumAND(std::vector<int>& nums, int k, int m);
};

}  // namespace problem_3806
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_BITWISE_AND_AFTER_INCREMENT_OPERATIONS_H_
