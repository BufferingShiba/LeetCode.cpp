
#include "leetcode/core.h"

namespace leetcode {
namespace problem_3039 {

using Func = std::function<string(string)>;

class ApplyOperationsToMakeStringEmptySolution : public SolutionBase<Func> {
 public:
  //! 3039. Apply Operations to Make String Empty
  //! https://leetcode.com/problems/apply-operations-to-make-string-empty/
  string lastNonEmptyString(string s);

  ApplyOperationsToMakeStringEmptySolution();
};

}  // namespace problem_3039
}  // namespace leetcode
