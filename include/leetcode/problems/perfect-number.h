#include "leetcode/core.h"

namespace leetcode {
namespace problem_507 {

using Func = std::function<bool(int)>;

class PerfectNumberSolution : public SolutionBase<Func> {
 public:
  //! 507. Perfect Number
  //! https://leetcode.com/problems/perfect-number/
  bool checkPerfectNumber(int num);

  PerfectNumberSolution();
};

}  // namespace problem_507
}  // namespace leetcode
