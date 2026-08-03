#ifndef LEETCODE_PROBLEMS_FIRST_LETTER_TO_APPEAR_TWICE_H__
#define LEETCODE_PROBLEMS_FIRST_LETTER_TO_APPEAR_TWICE_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2351 {

using Func = std::function<char(std::string)>;

class FirstLetterToAppearTwiceSolution : public SolutionBase<Func> {
 public:
  FirstLetterToAppearTwiceSolution();

  char repeatedCharacter(std::string s);
};

}  // namespace problem_2351
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIRST_LETTER_TO_APPEAR_TWICE_H__
