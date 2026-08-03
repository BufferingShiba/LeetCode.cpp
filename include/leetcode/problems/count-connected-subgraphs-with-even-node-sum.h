#ifndef LEETCODE_PROBLEMS_COUNT_CONNECTED_SUBGRAPHS_WITH_EVEN_NODE_SUM_H_
#define LEETCODE_PROBLEMS_COUNT_CONNECTED_SUBGRAPHS_WITH_EVEN_NODE_SUM_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3910 {

using Func = std::function<int(std::vector<int>&, std::vector<std::vector<int>>&)>;

class CountConnectedSubgraphsWithEvenNodeSumSolution
    : public SolutionBase<Func> {
 public:
  CountConnectedSubgraphsWithEvenNodeSumSolution();

  int evenSumSubgraphs(std::vector<int>& nums,
                       std::vector<std::vector<int>>& edges);
};

}  // namespace problem_3910
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_CONNECTED_SUBGRAPHS_WITH_EVEN_NODE_SUM_H_
