#ifndef LEETCODE_PROBLEMS_FIND_THE_K_TH_CHARACTER_IN_STRING_GAME_II_H_
#define LEETCODE_PROBLEMS_FIND_THE_K_TH_CHARACTER_IN_STRING_GAME_II_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3307 {

using Func = std::function<char(long long k, std::vector<int>& operations)>;

class FindTheKThCharacterInStringGameIiSolution
    : public SolutionBase<Func> {
 public:
  FindTheKThCharacterInStringGameIiSolution();
  char kthCharacter(long long k, std::vector<int>& operations);
};

}  // namespace problem_3307
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_K_TH_CHARACTER_IN_STRING_GAME_II_H_
