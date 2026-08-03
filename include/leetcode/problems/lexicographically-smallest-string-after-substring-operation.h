#ifndef LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_STRING_AFTER_SUBSTRING_OPERATION_H__
#define LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_STRING_AFTER_SUBSTRING_OPERATION_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2734 {

using Func = std::function<std::string(std::string)>;

class LexicographicallySmallestStringAfterSubstringOperationSolution
    : public SolutionBase<Func> {
 public:
  LexicographicallySmallestStringAfterSubstringOperationSolution();

  std::string smallestString(std::string s);
};

}  // namespace leetcode::problem_2734

#endif  // LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_STRING_AFTER_SUBSTRING_OPERATION_H__
