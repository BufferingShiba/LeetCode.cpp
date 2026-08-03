#include "leetcode/problems/n-ary-tree-postorder-traversal.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_590 {

namespace {

// Iterative postorder: do a pre-order-like traversal (root then children pushed
// to a stack), then reverse the result to obtain postorder.
std::vector<int> postorderIterative(Node* root) {
  std::vector<int> result;
  if (root == nullptr) {
    return result;
  }
  std::vector<Node*> stack;
  stack.push_back(root);
  while (!stack.empty()) {
    Node* node = stack.back();
    stack.pop_back();
    result.push_back(node->val);
    for (Node* child : node->children) {
      stack.push_back(child);
    }
  }
  std::reverse(result.begin(), result.end());
  return result;
}

}  // namespace

NAryTreePostorderTraversalSolution::NAryTreePostorderTraversalSolution() {
  setMetaInfo(
      {590, "N-ary Tree Postorder Traversal",
       "https://leetcode.com/problems/n-ary-tree-postorder-traversal/"});
  registerStrategy(
      {.name = "Iterative",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Stack", "Tree", "DFS"}},
      postorderIterative);
}

std::vector<int> NAryTreePostorderTraversalSolution::postorder(Node* root) {
  return getSolution()(root);
}

}  // namespace problem_590
}  // namespace leetcode
