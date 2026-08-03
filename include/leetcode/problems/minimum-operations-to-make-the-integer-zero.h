#include "leetcode/core.h"

namespace leetcode {
namespace problem_2749 {

using Func = std::function<int(int, int)>;

class MinimumOperationsToMakeTheIntegerZeroSolution : public SolutionBase<Func> {
 public:
  //! 2749. Minimum Operations to Make the Integer Zero
  //! https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/
  int makeTheIntegerZero(int num1, int num2);

  MinimumOperationsToMakeTheIntegerZeroSolution();
};

}  // namespace problem_2749
}  // namespace leetcode
