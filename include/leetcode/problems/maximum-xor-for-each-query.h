#ifndef LEETCODE_PROBLEMS_MAXIMUM_XOR_FOR_EACH_QUERY_H__
#define LEETCODE_PROBLEMS_MAXIMUM_XOR_FOR_EACH_QUERY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1829 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class MaximumXorForEachQuerySolution : public SolutionBase<Func> {
 public:
  MaximumXorForEachQuerySolution();

  std::vector<int> getMaximumXor(std::vector<int>& nums, int maximumBit);
};

}  // namespace leetcode::problem_1829

#endif  // LEETCODE_PROBLEMS_MAXIMUM_XOR_FOR_EACH_QUERY_H__
