#include "leetcode/core.h"

#include <vector>

namespace leetcode {
namespace problem_429 {

//! Definition for an N-ary tree node.
struct Node {
  int val;
  std::vector<Node*> children;

  Node() {}
  explicit Node(int _val) : val(_val) {}
  Node(int _val, std::vector<Node*> _children)
      : val(_val), children(std::move(_children)) {}
  ~Node() {
    for (Node* c : children) delete c;
  }
};

using Func = std::function<std::vector<std::vector<int>>(Node*)>;

class NAryTreeLevelOrderTraversalSolution : public SolutionBase<Func> {
 public:
  //! 429. N-ary Tree Level Order Traversal
  //! https://leetcode.com/problems/n-ary-tree-level-order-traversal/
  std::vector<std::vector<int>> levelOrder(Node* root);

  NAryTreeLevelOrderTraversalSolution();
};

}  // namespace problem_429
}  // namespace leetcode
