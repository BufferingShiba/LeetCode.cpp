#ifndef LEETCODE_PROBLEMS_SPLIT_A_STRING_IN_BALANCED_STRINGS_H__
#define LEETCODE_PROBLEMS_SPLIT_A_STRING_IN_BALANCED_STRINGS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1221 {

class SplitAStringInBalancedStringsSolution
    : public SolutionBase<std::function<int(const std::string&)>> {
 public:
  SplitAStringInBalancedStringsSolution();

  int balancedStringSplit(const std::string& s);
};

}  // namespace leetcode::problem_1221

#endif  // LEETCODE_PROBLEMS_SPLIT_A_STRING_IN_BALANCED_STRINGS_H__
