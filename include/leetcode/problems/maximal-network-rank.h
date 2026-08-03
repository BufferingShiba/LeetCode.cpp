#ifndef LEETCODE_PROBLEMS_MAXIMAL_NETWORK_RANK_H__
#define LEETCODE_PROBLEMS_MAXIMAL_NETWORK_RANK_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_1615 {

using Func = std::function<int(int, std::vector<std::vector<int>>&)>;

class MaximalNetworkRankSolution : public SolutionBase<Func> {
 public:
  int maximalNetworkRank(int n, std::vector<std::vector<int>>& roads);

  MaximalNetworkRankSolution();
};

}  // namespace leetcode::problem_1615

#endif
