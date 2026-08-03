#ifndef LEETCODE_PROBLEM_762_H_
#define LEETCODE_PROBLEM_762_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_762 {

using Func = std::function<int(int, int)>;

class PrimeNumberOfSetBitsInBinaryRepresentationSolution : public SolutionBase<Func> {
 public:
  PrimeNumberOfSetBitsInBinaryRepresentationSolution();
  int countPrimeSetBits(int left, int right);
};

}  // namespace problem_762
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_762_H_
