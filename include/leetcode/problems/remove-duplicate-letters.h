#ifndef LEETCODE_PROBLEMS_REMOVE_DUPLICATE_LETTERS_H_
#define LEETCODE_PROBLEMS_REMOVE_DUPLICATE_LETTERS_H_

#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_316 {

using Func = std::function<std::string(std::string)>;

class RemoveDuplicateLettersSolution : public SolutionBase<Func> {
 public:
  RemoveDuplicateLettersSolution();

  std::string removeDuplicateLetters(std::string s);
};

}  // namespace leetcode::problem_316

#endif  // LEETCODE_PROBLEMS_REMOVE_DUPLICATE_LETTERS_H_
