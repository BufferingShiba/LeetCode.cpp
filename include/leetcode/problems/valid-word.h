#ifndef LEETCODE_PROBLEMS_VALID_WORD_H__
#define LEETCODE_PROBLEMS_VALID_WORD_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_3136 {

using Func = std::function<bool(std::string)>;

class ValidWordSolution : public SolutionBase<Func> {
 public:
  ValidWordSolution();
  bool isValid(std::string word);
};

}  // namespace leetcode::problem_3136

#endif  // LEETCODE_PROBLEMS_VALID_WORD_H__
