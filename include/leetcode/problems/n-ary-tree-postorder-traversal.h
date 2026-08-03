#ifndef LEETCODE_PROBLEMS_NARY_TREE_POSTORDER_TRAVERSAL_H__
#define LEETCODE_PROBLEMS_NARY_TREE_POSTORDER_TRAVERSAL_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

// Definition for a Node.
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
namespace problem_590 {

using Func = std::function<std::vector<int>(Node* root)>;

class NAryTreePostorderTraversalSolution : public SolutionBase<Func> {
 public:
  NAryTreePostorderTraversalSolution();

  std::vector<int> postorder(Node* root);
};

}  // namespace problem_590
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NARY_TREE_POSTORDER_TRAVERSAL_H__
