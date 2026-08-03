#include "leetcode/core.h"

namespace leetcode {
namespace problem_2546 {

using Func = std::function<bool(string, string)>;

class ApplyBitwiseOperationsToMakeStringsEqualSolution : public SolutionBase<Func> {
 public:
  //! 2546. Apply Bitwise Operations to Make Strings Equal
  //! https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/
  bool makeStringsEqual(string s, string target);

  ApplyBitwiseOperationsToMakeStringsEqualSolution();
};

}  // namespace problem_2546
}  // namespace leetcode
