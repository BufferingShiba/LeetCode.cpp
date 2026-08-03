#ifndef LEETCODE_PROBLEMS_EQUAL_SCORE_SUBSTRINGS_H_
#define LEETCODE_PROBLEMS_EQUAL_SCORE_SUBSTRINGS_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_3707 {

using Func = std::function<bool(std::string)>;

class EqualScoreSubstringsSolution : public SolutionBase<Func> {
public:
    EqualScoreSubstringsSolution();
    bool scoreBalance(std::string s);
};

}  // namespace leetcode::problem_3707

#endif  // LEETCODE_PROBLEMS_EQUAL_SCORE_SUBSTRINGS_H_
