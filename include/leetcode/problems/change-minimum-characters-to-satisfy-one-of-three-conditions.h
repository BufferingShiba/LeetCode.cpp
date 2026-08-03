#ifndef LEETCODE_PROBLEMS_CHANGE_MINIMUM_CHARACTERS_TO_SATISFY_ONE_OF_THREE_CONDITIONS_H__
#define LEETCODE_PROBLEMS_CHANGE_MINIMUM_CHARACTERS_TO_SATISFY_ONE_OF_THREE_CONDITIONS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_1737 {

using Func = std::function<int(std::string, std::string)>;

class ChangeMinimumCharactersToSatisfyOneOfThreeConditionsSolution
    : public SolutionBase<Func> {
 public:
  ChangeMinimumCharactersToSatisfyOneOfThreeConditionsSolution();
  int minCharacters(std::string a, std::string b);
};

}  // namespace problem_1737
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHANGE_MINIMUM_CHARACTERS_TO_SATISFY_ONE_OF_THREE_CONDITIONS_H__
