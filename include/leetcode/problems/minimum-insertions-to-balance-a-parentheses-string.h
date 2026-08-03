#ifndef LEETCODE_PROBLEMS_MINIMUM_INSERTIONS_TO_BALANCE_A_PARENTHESES_STRING_H
#define LEETCODE_PROBLEMS_MINIMUM_INSERTIONS_TO_BALANCE_A_PARENTHESES_STRING_H

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode::problem_1541 {

using Func = std::function<int(std::string)>;

class MinimumInsertionsToBalanceAParenthesesStringSolution : public SolutionBase<Func> {
public:
    MinimumInsertionsToBalanceAParenthesesStringSolution();

    int minInsertions(std::string s);
};

}  // namespace leetcode::problem_1541

#endif  // LEETCODE_PROBLEMS_MINIMUM_INSERTIONS_TO_BALANCE_A_PARENTHESES_STRING_H
