#ifndef LEETCODE_PROBLEMS_LARGEST_NUMBER_AFTER_DIGIT_SWAPS_BY_PARITY_H__
#define LEETCODE_PROBLEMS_LARGEST_NUMBER_AFTER_DIGIT_SWAPS_BY_PARITY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2231 {

using Func = std::function<int(int)>;

class LargestNumberAfterDigitSwapsByParitySolution
    : public SolutionBase<Func> {
 public:
  LargestNumberAfterDigitSwapsByParitySolution();

  int largestInteger(int num);
};

}  // namespace problem_2231
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LARGEST_NUMBER_AFTER_DIGIT_SWAPS_BY_PARITY_H__
