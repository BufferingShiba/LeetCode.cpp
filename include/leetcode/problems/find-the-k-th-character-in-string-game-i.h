#ifndef LEETCODE_PROBLEMS_FIND_THE_K_TH_CHARACTER_IN_STRING_GAME_I_H_
#define LEETCODE_PROBLEMS_FIND_THE_K_TH_CHARACTER_IN_STRING_GAME_I_H_

#include "leetcode/core.h"

#include <functional>

namespace leetcode::problem_3304 {

using Func = std::function<char(int)>;

class FindTheKThCharacterInStringGameISolution
    : public SolutionBase<Func> {
 public:
  char kthCharacter(int k);

  FindTheKThCharacterInStringGameISolution();
};

}  // namespace leetcode::problem_3304

#endif  // LEETCODE_PROBLEMS_FIND_THE_K_TH_CHARACTER_IN_STRING_GAME_I_H_
