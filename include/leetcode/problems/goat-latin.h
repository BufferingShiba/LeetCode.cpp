#ifndef LEETCODE_PROBLEMS_GOAT_LATIN_H__
#define LEETCODE_PROBLEMS_GOAT_LATIN_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_824 {

using Func = std::function<std::string(std::string)>;

class GoatLatinSolution : public SolutionBase<Func> {
 public:
  GoatLatinSolution();

  std::string toGoatLatin(std::string sentence);
};

}  // namespace leetcode::problem_824

#endif  // LEETCODE_PROBLEMS_GOAT_LATIN_H__
