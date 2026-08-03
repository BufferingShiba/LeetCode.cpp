#ifndef LEETCODE_PROBLEMS_LAST_SUBSTRING_IN_LEXICOGRAPHICAL_ORDER_H
#define LEETCODE_PROBLEMS_LAST_SUBSTRING_IN_LEXICOGRAPHICAL_ORDER_H

#include "leetcode/core.h"

namespace leetcode::problem_1163 {

using Func = std::function<std::string(std::string)>;

class LastSubstringInLexicographicalOrderSolution : public SolutionBase<Func> {
 public:
  LastSubstringInLexicographicalOrderSolution();
  std::string lastSubstring(std::string s);
};

}  // namespace leetcode::problem_1163

#endif  // LEETCODE_PROBLEMS_LAST_SUBSTRING_IN_LEXICOGRAPHICAL_ORDER_H
