#ifndef LEETCODE_PROBLEMS_FIND_SPECIAL_SUBSTRING_OF_LENGTH_K_H__
#define LEETCODE_PROBLEMS_FIND_SPECIAL_SUBSTRING_OF_LENGTH_K_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_3456 {

using Func = std::function<bool(std::string, int)>;

class FindSpecialSubstringOfLengthKSolution
    : public SolutionBase<Func> {
 public:
  bool hasSpecialSubstring(std::string s, int k);

  FindSpecialSubstringOfLengthKSolution();
};

}  // namespace leetcode::problem_3456

#endif  // LEETCODE_PROBLEMS_FIND_SPECIAL_SUBSTRING_OF_LENGTH_K_H__
