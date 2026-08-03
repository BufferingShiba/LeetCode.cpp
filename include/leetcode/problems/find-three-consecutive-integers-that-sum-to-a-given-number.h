#ifndef LEETCODE_PROBLEM_2177_H
#define LEETCODE_PROBLEM_2177_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2177 {

using Func = std::function<std::vector<long long>(long long)>;

class FindThreeConsecutiveIntegersThatSumToAGivenNumberSolution : public SolutionBase<Func> {
 public:
  FindThreeConsecutiveIntegersThatSumToAGivenNumberSolution();

  std::vector<long long> sumOfThree(long long num);
};

}  // namespace problem_2177
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_2177_H
