#include "leetcode/problems/flatten-a-multilevel-doubly-linked-list.h"

#include <utility>

namespace leetcode {
namespace problem_430 {

namespace {

// Iteratively flatten the multilevel doubly linked list in place.
// One pass over the gradually-expanded main list; whenever a node with a
// child is met, splice its child list between that node and its current next.
// Every node is scanned twice in total (once when its own level is spliced,
// once during the main traversal), so the time is O(n) with O(1) extra space.
Node* flattenImpl(Node* head) {
  Node* cur = head;
  while (cur != nullptr) {
    if (cur->child != nullptr) {
      Node* childHead = cur->child;
      Node* childTail = childHead;
      while (childTail->next != nullptr) {
        childTail = childTail->next;
      }

      Node* next = cur->next;

      // Connect cur -> childHead.
      cur->next = childHead;
      childHead->prev = cur;

      // Connect childTail -> next (if any).
      if (next != nullptr) {
        childTail->next = next;
        next->prev = childTail;
      }

      cur->child = nullptr;
    }
    cur = cur->next;
  }
  return head;
}

}  // namespace

FlattenAMultilevelDoublyLinkedListSolution::
    FlattenAMultilevelDoublyLinkedListSolution() {
  setMetaInfo({.id = 430,
               .title = "Flatten a Multilevel Doubly Linked List",
               .url = "https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/"});
  registerStrategy(
      {"Iterative In-place Splice", "Accepted", "O(n)", "O(1)",
       {"Linked List", "Depth-First Search", "Doubly-Linked List"}},
      flattenImpl);
}

Node* FlattenAMultilevelDoublyLinkedListSolution::flatten(Node* head) {
  return getSolution()(head);
}

}  // namespace problem_430
}  // namespace leetcode
