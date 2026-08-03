#include "leetcode/core.h"

namespace leetcode {
namespace problem_633 {

using Func = std::function<bool(int)>;

class SumOfSquareNumbersSolution : public SolutionBase<Func> {
 public:
  //! 633. Sum of Square Numbers
  //! https://leetcode.com/problems/sum-of-square-numbers/
  bool judgeSquareSum(int c);

  SumOfSquareNumbersSolution();
};

}  // namespace problem_633
}  // namespace leetcode
