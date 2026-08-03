#ifndef LEETCODE_PYTHAGOREAN_DISTANCE_NODES_IN_A_TREE_H__
#define LEETCODE_PYTHAGOREAN_DISTANCE_NODES_IN_A_TREE_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3820 {

using Func = std::function<int(int, std::vector<std::vector<int>>&, int, int, int)>;

class PythagoreanDistanceNodesInATreeSolution : public SolutionBase<Func> {
 public:
  PythagoreanDistanceNodesInATreeSolution();
  int specialNodes(int n, std::vector<std::vector<int>>& edges, int x, int y,
                   int z);
};

}  // namespace problem_3820
}  // namespace leetcode

#endif  // LEETCODE_PYTHAGOREAN_DISTANCE_NODES_IN_A_TREE_H__
