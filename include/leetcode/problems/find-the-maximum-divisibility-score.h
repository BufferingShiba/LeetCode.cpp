#ifndef LEETCODE_PROBLEMS_FIND_THE_MAXIMUM_DIVISIBILITY_SCORE_H__
#define LEETCODE_PROBLEMS_FIND_THE_MAXIMUM_DIVISIBILITY_SCORE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2644 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class FindTheMaximumDivisibilityScoreSolution
    : public SolutionBase<Func> {
 public:
  FindTheMaximumDivisibilityScoreSolution();

  int maxDivScore(std::vector<int>& nums, std::vector<int>& divisors);
};

}  // namespace problem_2644
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_MAXIMUM_DIVISIBILITY_SCORE_H__
