#ifndef LEETCODE_PROBLEM_3801_H
#define LEETCODE_PROBLEM_3801_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3801 {

using Func = std::function<long long(std::vector<std::vector<int>>&)>;

class MinimumCostToMergeSortedListsSolution : public SolutionBase<Func> {
 public:
  MinimumCostToMergeSortedListsSolution();
  long long minMergeCost(std::vector<std::vector<int>>& lists);
};

}  // namespace problem_3801
}  // namespace leetcode

#endif
