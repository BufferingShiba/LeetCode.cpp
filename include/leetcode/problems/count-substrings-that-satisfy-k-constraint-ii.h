#ifndef LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_THAT_SATISFY_K_CONSTRAINT_II_H__
#define LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_THAT_SATISFY_K_CONSTRAINT_II_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3261 {

using Func =
    std::function<std::vector<long long>(std::string, int,
                                         std::vector<std::vector<int>>&)>;

class CountSubstringsThatSatisfyKConstraintIiSolution
    : public SolutionBase<Func> {
 public:
  CountSubstringsThatSatisfyKConstraintIiSolution();

  std::vector<long long> countKConstraintSubstrings(
      std::string s, int k, std::vector<std::vector<int>>& queries);
};

}  // namespace leetcode::problem_3261

#endif  // LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_THAT_SATISFY_K_CONSTRAINT_II_H__
