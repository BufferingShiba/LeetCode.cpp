#ifndef LEETCODE_PROBLEMS_FIND_VALID_PAIR_OF_ADJACENT_DIGITS_IN_STRING_H__
#define LEETCODE_PROBLEMS_FIND_VALID_PAIR_OF_ADJACENT_DIGITS_IN_STRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_3438 {

using Func = std::function<std::string(std::string)>;

class FindValidPairOfAdjacentDigitsInStringSolution
    : public SolutionBase<Func> {
 public:
  FindValidPairOfAdjacentDigitsInStringSolution();

  std::string findValidPair(std::string s);
};

}  // namespace leetcode::problem_3438

#endif  // LEETCODE_PROBLEMS_FIND_VALID_PAIR_OF_ADJACENT_DIGITS_IN_STRING_H__
