#ifndef LEETCODE_PROBLEMS_COUNT_PAIRS_THAT_FORM_A_COMPLETE_DAY_I_H_
#define LEETCODE_PROBLEMS_COUNT_PAIRS_THAT_FORM_A_COMPLETE_DAY_I_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_3184 {

using Func = std::function<int(std::vector<int>&)>;

class CountPairsThatFormACompleteDayISolution
    : public SolutionBase<Func> {
 public:
  CountPairsThatFormACompleteDayISolution();

  int countCompleteDayPairs(std::vector<int>& hours);
};

}  // namespace leetcode::problem_3184

#endif  // LEETCODE_PROBLEMS_COUNT_PAIRS_THAT_FORM_A_COMPLETE_DAY_I_H_
