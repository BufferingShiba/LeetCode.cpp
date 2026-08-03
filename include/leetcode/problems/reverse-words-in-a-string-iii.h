#ifndef LEETCODE_PROBLEMS_REVERSE_WORDS_IN_A_STRING_III_H_
#define LEETCODE_PROBLEMS_REVERSE_WORDS_IN_A_STRING_III_H_

#include "leetcode/core.h"

namespace leetcode::problem_557 {

using Func = std::function<std::string(std::string)>;

class ReverseWordsInAStringIiiSolution : public SolutionBase<Func> {
 public:
  ReverseWordsInAStringIiiSolution();

  std::string reverseWords(std::string s);
};

}  // namespace leetcode::problem_557

#endif  // LEETCODE_PROBLEMS_REVERSE_WORDS_IN_A_STRING_III_H_
