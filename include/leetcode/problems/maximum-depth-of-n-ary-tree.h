#ifndef LEETCODE_PROBLEMS_MAXIMUM_DEPTH_OF_N_ARY_TREE_H_
#define LEETCODE_PROBLEMS_MAXIMUM_DEPTH_OF_N_ARY_TREE_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

// Definition for a Node (N-ary tree).
class Node {
 public:
  int val;
  std::vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, std::vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

namespace leetcode {
namespace problem_559 {

using Func = std::function<int(Node*)>;

class MaximumDepthOfNAryTreeSolution : public SolutionBase<Func> {
 public:
  MaximumDepthOfNAryTreeSolution();

  int maxDepth(Node* root);
};

}  // namespace problem_559
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_DEPTH_OF_N_ARY_TREE_H_
