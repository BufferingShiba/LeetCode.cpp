#include "leetcode/core.h"

#include <functional>

namespace leetcode::problem_3918 {

class SumOfPrimesBetweenNumberAndItsReverseSolution
    : public SolutionBase<std::function<int(int)>> {
 public:
  int sumOfPrimesInRange(int n);

  SumOfPrimesBetweenNumberAndItsReverseSolution();
};

}  // namespace leetcode::problem_3918
