#include "leetcode/problems/closest-nodes-queries-in-a-binary-search-tree.h"

#include <algorithm>

namespace leetcode {
namespace problem_2476 {

namespace {

std::vector<std::vector<int>> closestNodesImpl(TreeNode* root,
                                               std::vector<int>& queries) {
  // In-order traversal of BST yields a sorted array.
  std::vector<int> inorder;
  std::vector<TreeNode*> stack;
  TreeNode* cur = root;
  while (cur || !stack.empty()) {
    while (cur) {
      stack.push_back(cur);
      cur = cur->left;
    }
    cur = stack.back();
    stack.pop_back();
    inorder.push_back(cur->val);
    cur = cur->right;
  }

  std::vector<std::vector<int>> answer;
  answer.reserve(queries.size());
  for (int q : queries) {
    // largest value <= q
    int mini = -1;
    auto it = std::upper_bound(inorder.begin(), inorder.end(), q);
    if (it != inorder.begin()) {
      mini = *(it - 1);
    }

    // smallest value >= q
    int maxi = -1;
    auto it2 = std::lower_bound(inorder.begin(), inorder.end(), q);
    if (it2 != inorder.end()) {
      maxi = *it2;
    }

    answer.push_back({mini, maxi});
  }
  return answer;
}

}  // namespace

ClosestNodesQueriesInABinarySearchTreeSolution::
    ClosestNodesQueriesInABinarySearchTreeSolution() {
  setMetaInfo({.id = 2476,
               .title =
                   "Closest Nodes Queries in a Binary Search Tree",
               .url = "https://leetcode.com/problems/closest-nodes-queries-"
                      "in-a-binary-search-tree/"});
  registerStrategy(
      {.name = "inorder_binary_search",
       .expected = "Accepted",
       .time_complexity = "O(N + n log N)",
       .space_complexity = "O(N)",
       .tags = {"Tree", "Binary Search Tree", "Binary Search",
                "Depth-First Search"},
       .notes =
           "In-order traversal yields sorted array; binary search per query."},
      closestNodesImpl);
}

std::vector<std::vector<int>>
ClosestNodesQueriesInABinarySearchTreeSolution::closestNodes(
    TreeNode* root, std::vector<int>& queries) {
  return getSolution()(root, queries);
}

}  // namespace problem_2476
}  // namespace leetcode
