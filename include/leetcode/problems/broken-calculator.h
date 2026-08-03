#include "leetcode/core.h"

namespace leetcode {
namespace problem_991 {

using Func = std::function<int(int, int)>;

class BrokenCalculatorSolution : public SolutionBase<Func> {
 public:
  //! 991. Broken Calculator
  //! https://leetcode.com/problems/broken-calculator/
  int brokenCalc(int startValue, int target);

  BrokenCalculatorSolution();
};

}  // namespace problem_991
}  // namespace leetcode
