#include "leetcode/core.h"

namespace leetcode {
namespace problem_7 {

using Func = std::function<int(int)>;

class ReverseIntegerSolution : public SolutionBase<Func> {
 public:
  //! 7. Reverse Integer
  //! https://leetcode.com/problems/reverse-integer/
  int reverse(int x);

  ReverseIntegerSolution();
};

}  // namespace problem_7
}  // namespace leetcode
