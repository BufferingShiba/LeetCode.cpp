#ifndef LEETCODE_MINIMUM_ADDITIONS_TO_MAKE_VALID_STRING_H__
#define LEETCODE_MINIMUM_ADDITIONS_TO_MAKE_VALID_STRING_H__

#include "leetcode/core.h"

namespace leetcode::problem_2645 {

using Func = std::function<int(std::string)>;

class MinimumAdditionsToMakeValidStringSolution : public SolutionBase<Func> {
 public:
  int addMinimum(std::string word);

  MinimumAdditionsToMakeValidStringSolution();
};

}  // namespace leetcode::problem_2645

#endif  // LEETCODE_MINIMUM_ADDITIONS_TO_MAKE_VALID_STRING_H__
