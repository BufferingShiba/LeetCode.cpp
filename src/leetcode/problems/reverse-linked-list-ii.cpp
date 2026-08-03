#include "leetcode/problems/reverse-linked-list-ii.h"

namespace leetcode::problem_92 {

static leetcode::ListNode* reverseBetweenImpl(leetcode::ListNode* head, int left, int right) {
  if (!head || left == right) return head;

  leetcode::ListNode dummy(0, head);
  leetcode::ListNode* prev = &dummy;

  // Move prev to the node just before position `left`
  for (int i = 1; i < left; ++i) {
    prev = prev->next;
  }

  // `curr` stays at position `left`; we repeatedly pull its next node
  // and insert it right after `prev` (head-insertion into the reversed segment)
  leetcode::ListNode* curr = prev->next;

  for (int i = left; i < right; ++i) {
    leetcode::ListNode* nextNode = curr->next;
    curr->next = nextNode->next;
    nextNode->next = prev->next;
    prev->next = nextNode;
  }

  return dummy.next;
}

ReverseLinkedListIiSolution::ReverseLinkedListIiSolution() {
  setMetaInfo({.id = 92, .title = "Reverse Linked List II",
               .url = "https://leetcode.com/problems/reverse-linked-list-ii/"});
  registerStrategy(
      {.name = "OnePass",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Linked List"}},
      reverseBetweenImpl);
  setDefaultStrategy();
}

leetcode::ListNode* ReverseLinkedListIiSolution::reverseBetween(
    leetcode::ListNode* head, int left, int right) {
  return getSolution()(head, left, right);
}

}  // namespace leetcode::problem_92
