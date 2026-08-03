#ifndef LEETCODE_PROBLEMS_MINIMUM_DEGREE_OF_A_CONNECTED_TRIO_IN_A_GRAPH_H__
#define LEETCODE_PROBLEMS_MINIMUM_DEGREE_OF_A_CONNECTED_TRIO_IN_A_GRAPH_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_1761 {

using Func = std::function<int(int, std::vector<std::vector<int>>&)>;

class MinimumDegreeOfAConnectedTrioInAGraphSolution
    : public SolutionBase<Func> {
 public:
  MinimumDegreeOfAConnectedTrioInAGraphSolution();
  int minTrioDegree(int n, std::vector<std::vector<int>>& edges);
};

}  // namespace leetcode::problem_1761

#endif  // LEETCODE_PROBLEMS_MINIMUM_DEGREE_OF_A_CONNECTED_TRIO_IN_A_GRAPH_H__
