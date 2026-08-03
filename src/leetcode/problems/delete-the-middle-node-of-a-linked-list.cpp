#include "leetcode/problems/delete-the-middle-node-of-a-linked-list.h"

namespace leetcode {
namespace problem_2095 {

namespace {

//! Strategy: fast & slow pointers.
//! Move slow one step and fast two steps per iteration; when fast hits the
//! end, slow points at the predecessor of the middle node, so we unlink it.
//! Edge case n == 1: the loop never runs, slow stays at dummy and the only
//! node is removed, returning nullptr.
//!
//! Note: we intentionally do NOT free the removed node here. The test harness
//! owns the linked-list nodes and walks/frees them itself; freeing a node
//! manually would leave a dangling pointer that the harness later reads,
//! causing a heap-use-after-free under ASan.
leetcode::ListNode* deleteMiddleImpl(leetcode::ListNode* head) {
  leetcode::ListNode dummy(0, head);
  leetcode::ListNode* slow = &dummy;
  leetcode::ListNode* fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  leetcode::ListNode* del = slow->next;
  slow->next = del->next;
  return dummy.next;
}

}  // namespace

DeleteTheMiddleNodeOfALinkedListSolution::
    DeleteTheMiddleNodeOfALinkedListSolution() {
  setMetaInfo({.id = 2095,
               .title = "Delete the Middle Node of a Linked List",
               .url = "https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/"});
  registerStrategy({.name = "FastSlowPointers",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Linked List", "Two Pointers"}},
                   deleteMiddleImpl);
}

leetcode::ListNode* DeleteTheMiddleNodeOfALinkedListSolution::deleteMiddle(
    leetcode::ListNode* head) {
  return getSolution()(head);
}

}  // namespace problem_2095
}  // namespace leetcode
