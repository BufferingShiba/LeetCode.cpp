#ifndef LEETCODE_PROBLEMS_MODIFY_GRAPH_EDGE_WEIGHTS_H
#define LEETCODE_PROBLEMS_MODIFY_GRAPH_EDGE_WEIGHTS_H

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2699 {

using Func = std::function<std::vector<std::vector<int>>(
    int, std::vector<std::vector<int>>&, int, int, int)>;

class ModifyGraphEdgeWeightsSolution : public SolutionBase<Func> {
 public:
  std::vector<std::vector<int>> modifiedGraphEdges(
      int n, std::vector<std::vector<int>>& edges, int source,
      int destination, int target);

  [[deprecated("Use default constructor + registerStrategy() instead.")]]
  explicit ModifyGraphEdgeWeightsSolution(int /*unused*/) {}

  ModifyGraphEdgeWeightsSolution() {
    setMetaInfo({.id = 2699,
                 .title = "Modify Graph Edge Weights",
                 .url = "https://leetcode.com/problems/modify-graph-edge-weights/"});
    registerStrategy({.name = "IterativeDijkstraFill",
                      .expected = "Accepted",
                      .time_complexity = "O(E^2 log V)",
                      .space_complexity = "O(V + E)",
                      .tags = {"Graph", "Shortest Path", "Heap"}},
                     modifiedGraphEdgesImpl);
  }

 private:
  static std::vector<std::vector<int>> modifiedGraphEdgesImpl(
      int n, std::vector<std::vector<int>>& edges, int source,
      int destination, int target);
};

}  // namespace leetcode::problem_2699

#endif  // LEETCODE_PROBLEMS_MODIFY_GRAPH_EDGE_WEIGHTS_H
