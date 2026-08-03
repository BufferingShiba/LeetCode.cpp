#ifndef LEETCODE_PROBLEMS_PRIME_IN_DIAGONAL_H__
#define LEETCODE_PROBLEMS_PRIME_IN_DIAGONAL_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode {
namespace problem_2614 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class PrimeInDiagonalSolution : public SolutionBase<Func> {
 public:
  PrimeInDiagonalSolution();

  int diagonalPrime(std::vector<std::vector<int>>& nums);
};

}  // namespace problem_2614
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PRIME_IN_DIAGONAL_H__
