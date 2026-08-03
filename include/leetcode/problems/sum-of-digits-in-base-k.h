#ifndef LEETCODE_PROBLEMS_SUM_OF_DIGITS_IN_BASE_K_H__
#define LEETCODE_PROBLEMS_SUM_OF_DIGITS_IN_BASE_K_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1837 {

using Func = std::function<int(int, int)>;

class SumOfDigitsInBaseKSolution : public SolutionBase<Func> {
 public:
  SumOfDigitsInBaseKSolution();

  int sumBase(int n, int k);
};

}  // namespace problem_1837
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUM_OF_DIGITS_IN_BASE_K_H__
