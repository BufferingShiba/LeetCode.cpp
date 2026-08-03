#ifndef LEETCODE_PROBLEMS_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_H__
#define LEETCODE_PROBLEMS_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_116 {

// Node definition for this problem (perfect binary tree with next pointer).
struct Node {
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val)
      : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

using Func = std::function<Node*(Node*)>;

class PopulatingNextRightPointersInEachNodeSolution
    : public SolutionBase<Func> {
 public:
  PopulatingNextRightPointersInEachNodeSolution() {
    setMetaInfo({
        .id = 116,
        .title = "Populating Next Right Pointers in Each Node",
        .url = "https://leetcode.com/problems/populating-next-right-pointers-in-each-node/",
    });

    registerStrategy(
        {
            .name = "level-by-level-using-next",
            .expected = "Accepted",
            .time_complexity = "O(n)",
            .space_complexity = "O(1)",
            .tags = {"Tree", "BFS", "Linked List"},
            .notes =
                "For a perfect binary tree, walk each level using the already "
                "established next pointers and connect the next level children, "
                "then descend to the leftmost node of the next level.",
        },
        [](Node* root) -> Node* {
          if (root == nullptr) {
            return nullptr;
          }
          Node* leftmost = root;
          while (leftmost->left != nullptr) {
            Node* curr = leftmost;
            while (curr != nullptr) {
              curr->left->next = curr->right;
              if (curr->next != nullptr) {
                curr->right->next = curr->next->left;
              }
              curr = curr->next;
            }
            leftmost = leftmost->left;
          }
          return root;
        });
  }

  Node* connect(Node* root) { return getSolution()(root); }
};

}  // namespace problem_116
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_H__
