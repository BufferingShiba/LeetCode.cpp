#ifndef LEETCODE_PROBLEMS_DETERMINE_IF_STRING_HALVES_ARE_ALIKE_H
#define LEETCODE_PROBLEMS_DETERMINE_IF_STRING_HALVES_ARE_ALIKE_H

#include "leetcode/core.h"

namespace leetcode::problem_1704 {

using Func = std::function<bool(std::string)>;

class DetermineIfStringHalvesAreAlikeSolution : public SolutionBase<Func> {
 public:
  DetermineIfStringHalvesAreAlikeSolution();
  bool halvesAreAlike(std::string s);
};

}  // namespace leetcode::problem_1704

#endif  // LEETCODE_PROBLEMS_DETERMINE_IF_STRING_HALVES_ARE_ALIKE_H
