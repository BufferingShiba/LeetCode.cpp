#ifndef LEETCODE_PROBLEMS_DESIGN_GRAPH_WITH_SHORTEST_PATH_CALCULATOR_H_
#define LEETCODE_PROBLEMS_DESIGN_GRAPH_WITH_SHORTEST_PATH_CALCULATOR_H_

#include <utility>
#include <vector>

namespace leetcode::problem_2642 {

class Graph {
 public:
  Graph(int n, std::vector<std::vector<int>>& edges);
  void addEdge(std::vector<int> edge);
  int shortestPath(int node1, int node2);

 private:
  int n_;
  std::vector<std::vector<std::pair<int, int>>> adj_;  // (to, cost)
};

}  // namespace leetcode::problem_2642

#endif  // LEETCODE_PROBLEMS_DESIGN_GRAPH_WITH_SHORTEST_PATH_CALCULATOR_H_
