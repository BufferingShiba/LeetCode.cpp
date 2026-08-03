#ifndef LEETCODE_PROBLEMS_DIVIDE_NODES_INTO_THE_MAXIMUM_NUMBER_OF_GROUPS_H__
#define LEETCODE_PROBLEMS_DIVIDE_NODES_INTO_THE_MAXIMUM_NUMBER_OF_GROUPS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2493 {

using Func = std::function<int(int, std::vector<std::vector<int>>&)>;

class DivideNodesIntoTheMaximumNumberOfGroupsSolution
    : public SolutionBase<Func> {
 public:
  DivideNodesIntoTheMaximumNumberOfGroupsSolution();

  int magnificentSets(int n, std::vector<std::vector<int>>& edges);
};

}  // namespace leetcode::problem_2493

#endif  // LEETCODE_PROBLEMS_DIVIDE_NODES_INTO_THE_MAXIMUM_NUMBER_OF_GROUPS_H__
