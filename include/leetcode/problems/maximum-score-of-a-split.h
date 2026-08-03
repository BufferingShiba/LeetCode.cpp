#ifndef LEETCODE_PROBLEMS_MAXIMUM_SCORE_OF_A_SPLIT_H__
#define LEETCODE_PROBLEMS_MAXIMUM_SCORE_OF_A_SPLIT_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3788 {

using Func = std::function<long long(std::vector<int>&)>;

class MaximumScoreOfASplitSolution
    : public SolutionBase<Func> {
 public:
  MaximumScoreOfASplitSolution();

  long long maximumScore(std::vector<int>& nums);
};

}  // namespace problem_3788
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_SCORE_OF_A_SPLIT_H__
