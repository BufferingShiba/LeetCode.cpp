#ifndef LEETCODE_PROBLEMS_LETTER_CASE_PERMUTATION_H__
#define LEETCODE_PROBLEMS_LETTER_CASE_PERMUTATION_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_784 {

using Func = std::function<std::vector<std::string>(std::string)>;

class LetterCasePermutationSolution : public SolutionBase<Func> {
 public:
  LetterCasePermutationSolution();

  std::vector<std::string> letterCasePermutation(std::string s);
};

}  // namespace leetcode::problem_784

#endif  // LEETCODE_PROBLEMS_LETTER_CASE_PERMUTATION_H__
