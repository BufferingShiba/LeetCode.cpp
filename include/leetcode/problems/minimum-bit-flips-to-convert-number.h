#ifndef LEETCODE_PROBLEMS_MINIMUM_BIT_FLIPS_TO_CONVERT_NUMBER_H_
#define LEETCODE_PROBLEMS_MINIMUM_BIT_FLIPS_TO_CONVERT_NUMBER_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2220 {

using Func = std::function<int(int, int)>;

class MinimumBitFlipsToConvertNumberSolution
    : public SolutionBase<Func> {
 public:
  MinimumBitFlipsToConvertNumberSolution();

  int minBitFlips(int start, int goal);
};

}  // namespace problem_2220
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_BIT_FLIPS_TO_CONVERT_NUMBER_H_
