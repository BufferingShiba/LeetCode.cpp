#include "leetcode/core.h"

namespace leetcode {
namespace problem_3941 {

using Func = std::function<int(string)>;

class PasswordStrengthSolution : public SolutionBase<Func> {
 public:
  //! 3941. Password Strength
  //! https://leetcode.com/problems/password-strength/
  int passwordStrength(string password);

  PasswordStrengthSolution();
};

}  // namespace problem_3941
}  // namespace leetcode
