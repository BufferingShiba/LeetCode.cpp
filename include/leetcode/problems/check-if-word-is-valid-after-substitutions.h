#ifndef LEETCODE_PROBLEM_CHECK_IF_WORD_IS_VALID_AFTER_SUBSTITUTIONS_H
#define LEETCODE_PROBLEM_CHECK_IF_WORD_IS_VALID_AFTER_SUBSTITUTIONS_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1003 {

using Func = std::function<bool(std::string)>;

class CheckIfWordIsValidAfterSubstitutionsSolution : public SolutionBase<Func> {
 public:
  CheckIfWordIsValidAfterSubstitutionsSolution();
  bool isValid(std::string s);
};

}  // namespace problem_1003
}  // namespace leetcode

#endif
