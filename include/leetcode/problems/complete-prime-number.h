#ifndef LEETCODE_PROBLEMS_COMPLETE_PRIME_NUMBER_H_
#define LEETCODE_PROBLEMS_COMPLETE_PRIME_NUMBER_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3765 {

using Func = std::function<bool(int)>;

class CompletePrimeNumberSolution : public SolutionBase<Func> {
 public:
  CompletePrimeNumberSolution();

  bool completePrime(int num);
};

}  // namespace problem_3765
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COMPLETE_PRIME_NUMBER_H_
