#ifndef LEETCODE_PROBLEMS_REVERSE_VOWELS_OF_A_STRING_H__
#define LEETCODE_PROBLEMS_REVERSE_VOWELS_OF_A_STRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_345 {

using Func = std::function<std::string(std::string)>;

class ReverseVowelsOfAStringSolution
    : public SolutionBase<Func> {
 public:
  ReverseVowelsOfAStringSolution();

  std::string reverseVowels(std::string s);
};

}  // namespace leetcode::problem_345

#endif  // LEETCODE_PROBLEMS_REVERSE_VOWELS_OF_A_STRING_H__
