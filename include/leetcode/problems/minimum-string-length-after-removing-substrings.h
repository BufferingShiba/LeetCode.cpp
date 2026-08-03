#ifndef LEETCODE_PROBLEMS_MINIMUM_STRING_LENGTH_AFTER_REMOVING_SUBSTRINGS_H_
#define LEETCODE_PROBLEMS_MINIMUM_STRING_LENGTH_AFTER_REMOVING_SUBSTRINGS_H_

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode::problem_2696 {

class MinimumStringLengthAfterRemovingSubstringsSolution
    : public SolutionBase<std::function<int(std::string)>> {
 public:
  MinimumStringLengthAfterRemovingSubstringsSolution();

  int minLength(const std::string& s);
};

}  // namespace leetcode::problem_2696

#endif  // LEETCODE_PROBLEMS_MINIMUM_STRING_LENGTH_AFTER_REMOVING_SUBSTRINGS_H_
