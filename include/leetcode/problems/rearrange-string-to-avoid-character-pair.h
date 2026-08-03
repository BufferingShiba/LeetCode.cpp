#ifndef LEETCODE_PROBLEMS_REARRANGE_STRING_TO_AVOID_CHARACTER_PAIR_H_
#define LEETCODE_PROBLEMS_REARRANGE_STRING_TO_AVOID_CHARACTER_PAIR_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_3992 {

using Func = std::function<std::string(std::string, char, char)>;

class RearrangeStringToAvoidCharacterPairSolution : public SolutionBase<Func> {
 public:
  RearrangeStringToAvoidCharacterPairSolution();

  std::string rearrangeString(std::string s, char x, char y);
};

}  // namespace leetcode::problem_3992

#endif  // LEETCODE_PROBLEMS_REARRANGE_STRING_TO_AVOID_CHARACTER_PAIR_H_
