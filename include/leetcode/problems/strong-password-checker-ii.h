#ifndef LEETCODE_PROBLEMS_STRONG_PASSWORD_CHECKER_II_H__
#define LEETCODE_PROBLEMS_STRONG_PASSWORD_CHECKER_II_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2299 {

using Func = std::function<bool(std::string)>;

class StrongPasswordCheckerIiSolution : public SolutionBase<Func> {
 public:
  StrongPasswordCheckerIiSolution();

  bool strongPasswordCheckerII(std::string password);
};

}  // namespace leetcode::problem_2299

#endif  // LEETCODE_PROBLEMS_STRONG_PASSWORD_CHECKER_II_H__
