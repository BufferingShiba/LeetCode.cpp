#ifndef LEETCODE_PROBLEMS_SUM_OF_PERFECT_SQUARE_ANCESTORS_H
#define LEETCODE_PROBLEMS_SUM_OF_PERFECT_SQUARE_ANCESTORS_H

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_3715 {

using Func = std::function<long long(int, std::vector<std::vector<int>>&, std::vector<int>&)>;

class SumOfPerfectSquareAncestorsSolution : public SolutionBase<Func> {
 public:
  SumOfPerfectSquareAncestorsSolution();

  long long sumOfAncestors(int n, std::vector<std::vector<int>>& edges,
                           std::vector<int>& nums);
};

}  // namespace leetcode::problem_3715

#endif  // LEETCODE_PROBLEMS_SUM_OF_PERFECT_SQUARE_ANCESTORS_H
