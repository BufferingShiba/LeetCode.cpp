#ifndef LEETCODE_PROBLEMS_MONOTONE_INCREASING_DIGITS_H__
#define LEETCODE_PROBLEMS_MONOTONE_INCREASING_DIGITS_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode {
namespace problem_738 {

using Func = std::function<int(int)>;

class MonotoneIncreasingDigitsSolution : public SolutionBase<Func> {
 public:
  MonotoneIncreasingDigitsSolution();

  int monotoneIncreasingDigits(int n);
};

}  // namespace problem_738
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MONOTONE_INCREASING_DIGITS_H__
