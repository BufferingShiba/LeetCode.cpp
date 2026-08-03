#ifndef LEETCODE_PROBLEMS_VOWELS_GAME_IN_A_STRING_H__
#define LEETCODE_PROBLEMS_VOWELS_GAME_IN_A_STRING_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode {
namespace problem_3227 {

using Func = std::function<bool(const std::string&)>;

class VowelsGameInAStringSolution : public SolutionBase<Func> {
 public:
  VowelsGameInAStringSolution();
  bool doesAliceWin(std::string s);
};

}  // namespace problem_3227
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_VOWELS_GAME_IN_A_STRING_H__
