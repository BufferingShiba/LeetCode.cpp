#ifndef LEETCODE_PROBLEM_1906_MINIMUM_ABSOLUTE_DIFFERENCE_QUERIES_H__
#define LEETCODE_PROBLEM_1906_MINIMUM_ABSOLUTE_DIFFERENCE_QUERIES_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1906 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<std::vector<int>>&)>;

class MinimumAbsoluteDifferenceQueriesSolution : public SolutionBase<Func> {
 public:
  MinimumAbsoluteDifferenceQueriesSolution();

  std::vector<int> minDifference(std::vector<int>& nums,
                                 std::vector<std::vector<int>>& queries);
};

}  // namespace problem_1906
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1906_MINIMUM_ABSOLUTE_DIFFERENCE_QUERIES_H__
