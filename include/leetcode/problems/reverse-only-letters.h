#ifndef LEETCODE_PROBLEMS_REVERSE_ONLY_LETTERS_H__
#define LEETCODE_PROBLEMS_REVERSE_ONLY_LETTERS_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode::problem_917 {

using Func = std::function<std::string(std::string)>;

class ReverseOnlyLettersSolution : public SolutionBase<Func> {
 public:
  ReverseOnlyLettersSolution();

  std::string reverseOnlyLetters(std::string s);
};

}  // namespace leetcode::problem_917

#endif  // LEETCODE_PROBLEMS_REVERSE_ONLY_LETTERS_H__
