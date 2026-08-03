#ifndef LEETCODE_PROBLEMS_REVERSE_PREFIX_OF_WORD_H__
#define LEETCODE_PROBLEMS_REVERSE_PREFIX_OF_WORD_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2000 {

using Func = std::function<std::string(std::string, char)>;

class ReversePrefixOfWordSolution : public SolutionBase<Func> {
 public:
  ReversePrefixOfWordSolution();

  std::string reversePrefix(std::string word, char ch);
};

}  // namespace leetcode::problem_2000

#endif  // LEETCODE_PROBLEMS_REVERSE_PREFIX_OF_WORD_H__
