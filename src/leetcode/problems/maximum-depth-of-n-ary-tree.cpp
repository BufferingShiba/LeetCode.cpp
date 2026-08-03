#include "leetcode/problems/maximum-depth-of-n-ary-tree.h"

#include <algorithm>

namespace leetcode {
namespace problem_559 {

static int maxDepthImpl(Node* root) {
  if (root == nullptr) {
    return 0;
  }
  int maxChildDepth = 0;
  for (Node* child : root->children) {
    int childDepth = maxDepthImpl(child);
    if (childDepth > maxChildDepth) {
      maxChildDepth = childDepth;
    }
  }
  return 1 + maxChildDepth;
}

MaximumDepthOfNAryTreeSolution::MaximumDepthOfNAryTreeSolution() {
  setMetaInfo({.id = 559,
               .title = "Maximum Depth of N-ary Tree",
               .url = "https://leetcode.com/problems/maximum-depth-of-n-ary-tree/"});
  registerStrategy(
      {.name = "DFS",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(h)",
       .tags = {"Tree", "Depth-First Search", "Breadth-First Search"}},
      maxDepthImpl);
}

int MaximumDepthOfNAryTreeSolution::maxDepth(Node* root) {
  return getSolution()(root);
}

}  // namespace problem_559
}  // namespace leetcode
