#include "leetcode/core.h"

namespace leetcode {
namespace problem_306 {

using Func = std::function<bool(string)>;

class AdditiveNumberSolution : public SolutionBase<Func> {
 public:
  //! 306. Additive Number
  //! https://leetcode.com/problems/additive-number/
  bool isAdditiveNumber(string num);

  AdditiveNumberSolution();
};

}  // namespace problem_306
}  // namespace leetcode
