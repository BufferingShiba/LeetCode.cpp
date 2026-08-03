#ifndef LEETCODE_PROBLEM_3185_H_
#define LEETCODE_PROBLEM_3185_H_

#include "leetcode/core.h"

namespace leetcode::problem_3185 {

using Func = std::function<long long(std::vector<int>&)>;

class CountPairsThatFormACompleteDayIiSolution : public SolutionBase<Func> {
 public:
  CountPairsThatFormACompleteDayIiSolution();

  long long countCompleteDayPairs(std::vector<int>& hours);
};

}  // namespace leetcode::problem_3185

#endif  // LEETCODE_PROBLEM_3185_H_
