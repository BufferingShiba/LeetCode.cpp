#include "leetcode/problems/swapping-nodes-in-a-linked-list.h"

namespace leetcode {
namespace problem_1721 {

namespace {

// Two pointers: locate k-th node from beginning and k-th node from end, then
// swap their values. O(n) time, O(1) space.
ListNode* swapNodesImpl(ListNode* head, int k) {
  ListNode* first = head;
  ListNode* fast = head;
  for (int i = 0; i < k - 1; ++i) {
    fast = fast->next;
  }
  first = fast;  // k-th node from the beginning

  ListNode* second = head;
  while (fast->next != nullptr) {
    fast = fast->next;
    second = second->next;
  }
  // fast now at tail, second is k-th node from the end (n-k+1-th node)

  std::swap(first->val, second->val);
  return head;
}

}  // namespace

SwappingNodesInALinkedListSolution::SwappingNodesInALinkedListSolution() {
  setMetaInfo({1721,
               "Swapping Nodes in a Linked List",
               "https://leetcode.com/problems/swapping-nodes-in-a-linked-list/"});
  registerStrategy(
      {"Two Pointers", "Accepted", "O(n)", "O(1)",
       {"Linked List", "Two Pointers"}},
      swapNodesImpl);
}

ListNode* SwappingNodesInALinkedListSolution::swapNodes(ListNode* head, int k) {
  return getSolution()(head, k);
}

}  // namespace problem_1721
}  // namespace leetcode
