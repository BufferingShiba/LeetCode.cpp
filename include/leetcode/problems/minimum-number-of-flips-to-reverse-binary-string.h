#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_FLIPS_TO_REVERSE_BINARY_STRING_H_
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_FLIPS_TO_REVERSE_BINARY_STRING_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3750 {

using Func = std::function<int(int)>;

class MinimumNumberOfFlipsToReverseBinaryStringSolution
    : public SolutionBase<Func> {
 public:
  MinimumNumberOfFlipsToReverseBinaryStringSolution();

  int minimumFlips(int n);
};

}  // namespace problem_3750
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_FLIPS_TO_REVERSE_BINARY_STRING_H_
