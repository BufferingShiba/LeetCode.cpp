// LeetCode 1996: The Number of Weak Characters in the Game
#ifndef LEETCODE_PROBLEMS_THE_NUMBER_OF_WEAK_CHARACTERS_IN_THE_GAME_H__
#define LEETCODE_PROBLEMS_THE_NUMBER_OF_WEAK_CHARACTERS_IN_THE_GAME_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode::problem_1996 {

// A character i is weak if there exists another character j with
// attack_j > attack_i and defense_j > defense_i (both strictly greater).
using Func = std::function<int(std::vector<std::vector<int>>&)>;

class TheNumberOfWeakCharactersInTheGameSolution
    : public SolutionBase<Func> {
 public:
  TheNumberOfWeakCharactersInTheGameSolution();

 protected:
  int numberOfWeakCharacters(std::vector<std::vector<int>>& properties);
};

}  // namespace leetcode::problem_1996

#endif  // LEETCODE_PROBLEMS_THE_NUMBER_OF_WEAK_CHARACTERS_IN_THE_GAME_H__
