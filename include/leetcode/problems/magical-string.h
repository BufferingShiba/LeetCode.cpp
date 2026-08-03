#include "leetcode/core.h"

namespace leetcode {
namespace problem_481 {

using Func = std::function<int(int)>;

class MagicalStringSolution : public SolutionBase<Func> {
 public:
  //! 481. Magical String
  //! https://leetcode.com/problems/magical-string/
  int magicalString(int n);

  MagicalStringSolution();
};

}  // namespace problem_481
}  // namespace leetcode
