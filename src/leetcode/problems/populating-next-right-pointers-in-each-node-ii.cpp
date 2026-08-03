#include "leetcode/problems/populating-next-right-pointers-in-each-node-ii.h"

namespace leetcode {
namespace problem_117 {

namespace {

// Iterative level-by-level linking using constant extra space.
// For each level, walk the next chain and link the children of all nodes
// on this level into the next level's chain via a dummy head.
Node* connectImpl(Node* root) {
  if (root == nullptr) {
    return nullptr;
  }
  Node* cur = root;
  while (cur != nullptr) {
    Node dummy(0);
    Node* tail = &dummy;
    for (Node* p = cur; p != nullptr; p = p->next) {
      if (p->left != nullptr) {
        tail->next = p->left;
        tail = tail->next;
      }
      if (p->right != nullptr) {
        tail->next = p->right;
        tail = tail->next;
      }
    }
    cur = dummy.next;  // first node of the next level
  }
  return root;
}

}  // namespace

PopulatingNextRightPointersInEachNodeIiSolution::
    PopulatingNextRightPointersInEachNodeIiSolution() {
  setMetaInfo({.id = 117,
               .title = "Populating Next Right Pointers in Each Node II",
               .url = "https://leetcode.com/problems/"
                      "populating-next-right-pointers-in-each-node-ii/"});
  registerStrategy(
      {.name = "IterativeDummyHead",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Linked List", "Tree", "Breadth-First Search"},
       .notes =
           "Walk each level via next chain, link children into next level "
           "using a dummy head, constant extra space."},
      connectImpl);
}

Node* PopulatingNextRightPointersInEachNodeIiSolution::connect(Node* root) {
  return getSolution()(root);
}

}  // namespace problem_117
}  // namespace leetcode
