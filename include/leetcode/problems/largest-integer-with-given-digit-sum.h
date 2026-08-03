#ifndef LEETCODE_PROBLEM_4000_H_
#define LEETCODE_PROBLEM_4000_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_4000 {

using Func = std::function<int(int, int)>;

class LargestIntegerWithGivenDigitSumSolution : public SolutionBase<Func> {
 public:
  LargestIntegerWithGivenDigitSumSolution();

  int largestInteger(int n, int s);
};

}  // namespace problem_4000
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_4000_H_
