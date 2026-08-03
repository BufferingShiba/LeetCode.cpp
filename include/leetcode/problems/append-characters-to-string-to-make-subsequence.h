#ifndef LEETCODE_APPEND_CHARACTERS_TO_STRING_TO_MAKE_SUBSEQUENCE_H_
#define LEETCODE_APPEND_CHARACTERS_TO_STRING_TO_MAKE_SUBSEQUENCE_H_

#include <string>
#include "leetcode/core.h"

namespace leetcode::problem_2486 {

using Func = std::function<int(std::string, std::string)>;

class AppendCharactersToStringToMakeSubsequenceSolution : public SolutionBase<Func> {
 public:
  AppendCharactersToStringToMakeSubsequenceSolution();

  int appendCharacters(std::string s, std::string t);
};

}  // namespace leetcode::problem_2486

#endif  // LEETCODE_APPEND_CHARACTERS_TO_STRING_TO_MAKE_SUBSEQUENCE_H_
