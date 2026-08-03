#include "leetcode/core.h"

namespace leetcode {
namespace problem_3848 {

using Func = std::function<bool(int)>;

class CheckDigitorialPermutationSolution : public SolutionBase<Func> {
 public:
  //! 3848. Check Digitorial Permutation
  //! https://leetcode.com/problems/check-digitorial-permutation/
  bool isDigitorialPermutation(int n);

  CheckDigitorialPermutationSolution();
};

}  // namespace problem_3848
}  // namespace leetcode
