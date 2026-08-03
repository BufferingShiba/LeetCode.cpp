#ifndef LEETCODE_PROBLEMS_FIRST_MATCHING_CHARACTER_FROM_BOTH_ENDS_H__
#define LEETCODE_PROBLEMS_FIRST_MATCHING_CHARACTER_FROM_BOTH_ENDS_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode::problem_3884 {

using Func = std::function<int(std::string)>;

class FirstMatchingCharacterFromBothEndsSolution : public SolutionBase<Func> {
 public:
  FirstMatchingCharacterFromBothEndsSolution();

  int firstMatchingIndex(std::string s);
};

}  // namespace leetcode::problem_3884

#endif  // LEETCODE_PROBLEMS_FIRST_MATCHING_CHARACTER_FROM_BOTH_ENDS_H__
