#ifndef LEETCODE_PROBLEMS_REPLACE_ALL_S_TO_AVOID_CONSECUTIVE_REPEATING_CHARACTERS_H__
#define LEETCODE_PROBLEMS_REPLACE_ALL_S_TO_AVOID_CONSECUTIVE_REPEATING_CHARACTERS_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode {
namespace problem_1576 {

using Func = std::function<std::string(std::string)>;

class ReplaceAllSToAvoidConsecutiveRepeatingCharactersSolution
    : public SolutionBase<Func> {
 public:
  ReplaceAllSToAvoidConsecutiveRepeatingCharactersSolution();
  std::string modifyString(std::string s);
};

}  // namespace problem_1576
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REPLACE_ALL_S_TO_AVOID_CONSECUTIVE_REPEATING_CHARACTERS_H__
