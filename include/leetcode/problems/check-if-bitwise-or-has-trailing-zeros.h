#ifndef LEETCODE_PROBLEMS_CHECK_IF_BITWISE_OR_HAS_TRAILING_ZEROS_H__
#define LEETCODE_PROBLEMS_CHECK_IF_BITWISE_OR_HAS_TRAILING_ZEROS_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2980 {

using Func = std::function<bool(std::vector<int>&)>;

class CheckIfBitwiseOrHasTrailingZerosSolution : public SolutionBase<Func> {
 public:
  CheckIfBitwiseOrHasTrailingZerosSolution();
  bool hasTrailingZeros(std::vector<int>& nums);
};

}  // namespace problem_2980
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_BITWISE_OR_HAS_TRAILING_ZEROS_H__
