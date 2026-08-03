#include "leetcode/core.h"

namespace leetcode {
namespace problem_3407 {

using Func = std::function<bool(string, string)>;

class SubstringMatchingPatternSolution : public SolutionBase<Func> {
 public:
  //! 3407. Substring Matching Pattern
  //! https://leetcode.com/problems/substring-matching-pattern/
  bool hasMatch(string s, string p);

  SubstringMatchingPatternSolution();
};

}  // namespace problem_3407
}  // namespace leetcode
