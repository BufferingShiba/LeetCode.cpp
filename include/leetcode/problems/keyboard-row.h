#ifndef LEETCODE_PROBLEMS_KEYBOARD_ROW_H__
#define LEETCODE_PROBLEMS_KEYBOARD_ROW_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_500 {

using Func = std::function<std::vector<std::string>(std::vector<std::string>&)>;

class KeyboardRowSolution : public SolutionBase<Func> {
 public:
  KeyboardRowSolution();

  std::vector<std::string> findWords(std::vector<std::string>& words);
};

}  // namespace leetcode::problem_500

#endif  // LEETCODE_PROBLEMS_KEYBOARD_ROW_H__
