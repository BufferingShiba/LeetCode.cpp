#ifndef LEETCODE_PROBLEMS_TRIM_TRAILING_VOWELS_H__
#define LEETCODE_PROBLEMS_TRIM_TRAILING_VOWELS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_3856 {

using Func = std::function<std::string(std::string)>;

class TrimTrailingVowelsSolution : public SolutionBase<Func> {
 public:
  TrimTrailingVowelsSolution();

  std::string trimTrailingVowels(std::string s);
};

}  // namespace leetcode::problem_3856

#endif  // LEETCODE_PROBLEMS_TRIM_TRAILING_VOWELS_H__
