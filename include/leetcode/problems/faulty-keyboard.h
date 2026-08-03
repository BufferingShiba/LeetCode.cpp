#ifndef LEETCODE_PROBLEM_FAULTY_KEYBOARD_H
#define LEETCODE_PROBLEM_FAULTY_KEYBOARD_H

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode {
namespace problem_2810 {

using Func = std::function<std::string(std::string)>;

class FaultyKeyboardSolution : public SolutionBase<Func> {
 public:
  FaultyKeyboardSolution();

  std::string finalString(std::string s);
};

}  // namespace problem_2810
}  // namespace leetcode

#endif
