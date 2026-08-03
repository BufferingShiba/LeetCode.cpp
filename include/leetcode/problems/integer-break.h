#include "leetcode/core.h"

namespace leetcode {
namespace problem_343 {

using Func = std::function<int(int)>;

class IntegerBreakSolution : public SolutionBase<Func> {
 public:
  //! 343. Integer Break
  //! https://leetcode.com/problems/integer-break/
  int integerBreak(int n);

  IntegerBreakSolution();
};

}  // namespace problem_343
}  // namespace leetcode
