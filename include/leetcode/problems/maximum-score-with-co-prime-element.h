#ifndef LEETCODE_PROBLEMS_MAXIMUM_SCORE_WITH_CO_PRIME_ELEMENT_H_
#define LEETCODE_PROBLEMS_MAXIMUM_SCORE_WITH_CO_PRIME_ELEMENT_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3953 {

using Func =
    std::function<int(std::vector<int>&, int)>;

class MaximumScoreWithCoPrimeElementSolution : public SolutionBase<Func> {
 public:
  MaximumScoreWithCoPrimeElementSolution();

  int maxScore(std::vector<int>& nums, int maxVal);
};

}  // namespace problem_3953
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_SCORE_WITH_CO_PRIME_ELEMENT_H_
