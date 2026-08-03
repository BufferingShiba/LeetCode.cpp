#include "leetcode/core.h"

namespace leetcode {
namespace problem_1006 {

using Func = std::function<int(int)>;

class ClumsyFactorialSolution : public SolutionBase<Func> {
 public:
  //! 1006. Clumsy Factorial
  //! https://leetcode.com/problems/clumsy-factorial/
  int clumsy(int n);

  ClumsyFactorialSolution();
};

}  // namespace problem_1006
}  // namespace leetcode
