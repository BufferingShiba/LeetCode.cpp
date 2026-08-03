#ifndef LEETCODE_PROBLEMS_TAKE_K_OF_EACH_CHARACTER_FROM_LEFT_AND_RIGHT_H__
#define LEETCODE_PROBLEMS_TAKE_K_OF_EACH_CHARACTER_FROM_LEFT_AND_RIGHT_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_2516 {

using Func = std::function<int(std::string, int)>;

class TakeKOfEachCharacterFromLeftAndRightSolution
    : public SolutionBase<Func> {
 public:
  TakeKOfEachCharacterFromLeftAndRightSolution();

  int takeCharacters(std::string s, int k);
};

}  // namespace problem_2516
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TAKE_K_OF_EACH_CHARACTER_FROM_LEFT_AND_RIGHT_H__
