#ifndef LEETCODE_PROBLEMS_FIND_CENTER_OF_STAR_GRAPH_H_
#define LEETCODE_PROBLEMS_FIND_CENTER_OF_STAR_GRAPH_H_

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_1791 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class FindCenterOfStarGraphSolution : public SolutionBase<Func> {
 public:
  FindCenterOfStarGraphSolution();

  int findCenter(std::vector<std::vector<int>>& edges);
};

}  // namespace leetcode::problem_1791

#endif  // LEETCODE_PROBLEMS_FIND_CENTER_OF_STAR_GRAPH_H_
