#ifndef LEETCODE_PROBLEMS_REVERSE_LETTERS_THEN_SPECIAL_CHARACTERS_IN_A_STRING_H__
#define LEETCODE_PROBLEMS_REVERSE_LETTERS_THEN_SPECIAL_CHARACTERS_IN_A_STRING_H__

#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3823 {

using Func = std::function<std::string(std::string)>;

class ReverseLettersThenSpecialCharactersInAStringSolution
    : public SolutionBase<Func> {
 public:
  ReverseLettersThenSpecialCharactersInAStringSolution();

  // Problem entry point.
  std::string reverseByType(std::string s);
};

}  // namespace problem_3823
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REVERSE_LETTERS_THEN_SPECIAL_CHARACTERS_IN_A_STRING_H__
