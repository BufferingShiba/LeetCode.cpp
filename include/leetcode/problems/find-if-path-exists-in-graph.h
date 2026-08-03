#ifndef LEETCODE_PROBLEMS_FIND_IF_PATH_EXISTS_IN_GRAPH_H__
#define LEETCODE_PROBLEMS_FIND_IF_PATH_EXISTS_IN_GRAPH_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode {
namespace problem_1971 {

using Func = std::function<bool(int, std::vector<std::vector<int>>&, int, int)>;

class FindIfPathExistsInGraphSolution : public SolutionBase<Func> {
 public:
  FindIfPathExistsInGraphSolution();

  bool validPath(int n, std::vector<std::vector<int>>& edges, int source,
                 int destination);
};

}  // namespace problem_1971
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_IF_PATH_EXISTS_IN_GRAPH_H__
