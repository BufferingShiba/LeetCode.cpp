#ifndef LEETCODE_PROBLEM_3068_FIND_THE_MAXIMUM_SUM_OF_NODE_VALUES_H_
#define LEETCODE_PROBLEM_3068_FIND_THE_MAXIMUM_SUM_OF_NODE_VALUES_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3068 {

using Func = std::function<long long(std::vector<int>&, int, std::vector<std::vector<int>>&)>;

class FindTheMaximumSumOfNodeValuesSolution : public SolutionBase<Func> {
 public:
  FindTheMaximumSumOfNodeValuesSolution();
  long long maximumValueSum(std::vector<int>& nums, int k, std::vector<std::vector<int>>& edges);
};

}  // namespace problem_3068
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_3068_FIND_THE_MAXIMUM_SUM_OF_NODE_VALUES_H_
