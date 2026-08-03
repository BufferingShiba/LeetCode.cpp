#ifndef LEETCODE_PROBLEM_2193_H_
#define LEETCODE_PROBLEM_2193_H_

#include "leetcode/core.h"

namespace leetcode::problem_2193 {

using Func = std::function<int(std::string)>;

class MinimumNumberOfMovesToMakePalindromeSolution : public SolutionBase<Func> {
 public:
  MinimumNumberOfMovesToMakePalindromeSolution();

  int minMovesToMakePalindrome(std::string s);
};

}  // namespace leetcode::problem_2193

#endif  // LEETCODE_PROBLEM_2193_H_
