#ifndef LEETCODE_PROBLEM_1790_H__
#define LEETCODE_PROBLEM_1790_H__

#include "leetcode/core.h"

namespace leetcode::problem_1790 {

using Func = std::function<bool(std::string, std::string)>;

class CheckIfOneStringSwapCanMakeStringsEqualSolution : public SolutionBase<Func> {
 public:
  CheckIfOneStringSwapCanMakeStringsEqualSolution();

  bool areAlmostEqual(std::string s1, std::string s2);
};

}  // namespace leetcode::problem_1790

#endif  // LEETCODE_PROBLEM_1790_H__
