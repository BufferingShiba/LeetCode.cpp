#ifndef LEETCODE_PROBLEMS_FIND_IF_DIGIT_GAME_CAN_BE_WON_H__
#define LEETCODE_PROBLEMS_FIND_IF_DIGIT_GAME_CAN_BE_WON_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3232 {

using Func = std::function<bool(std::vector<int>&)>;

class FindIfDigitGameCanBeWonSolution : public SolutionBase<Func> {
 public:
  FindIfDigitGameCanBeWonSolution();

  bool canAliceWin(std::vector<int>& nums);
};

}  // namespace problem_3232
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_IF_DIGIT_GAME_CAN_BE_WON_H__
