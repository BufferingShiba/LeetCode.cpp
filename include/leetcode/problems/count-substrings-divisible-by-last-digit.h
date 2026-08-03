#ifndef LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_DIVISIBLE_BY_LAST_DIGIT_H_
#define LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_DIVISIBLE_BY_LAST_DIGIT_H_

#include "leetcode/core.h"

namespace leetcode::problem_3448 {

using Func = std::function<long long(std::string)>;

class CountSubstringsDivisibleByLastDigitSolution : public SolutionBase<Func> {
 public:
  CountSubstringsDivisibleByLastDigitSolution();

  long long countSubstrings(std::string s);
};

}  // namespace leetcode::problem_3448

#endif  // LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_DIVISIBLE_BY_LAST_DIGIT_H_
