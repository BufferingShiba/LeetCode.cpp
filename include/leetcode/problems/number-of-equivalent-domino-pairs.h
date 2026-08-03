#ifndef LEETCODE_PROBLEMS_NUMBER_OF_EQUIVALENT_DOMINO_PAIRS_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_EQUIVALENT_DOMINO_PAIRS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1128 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class NumberOfEquivalentDominoPairsSolution : public SolutionBase<Func> {
 public:
  NumberOfEquivalentDominoPairsSolution();

  int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes);
};

}  // namespace leetcode::problem_1128

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_EQUIVALENT_DOMINO_PAIRS_H__
