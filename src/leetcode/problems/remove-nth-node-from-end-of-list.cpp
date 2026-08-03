#include "leetcode/problems/remove-nth-node-from-end-of-list.h"

namespace leetcode {
namespace problem_19 {
namespace {

ListNode* removeNthFromEndImpl(ListNode* head, int n) {
  ListNode* dummy = new ListNode(0, head);
  ListNode* fast = dummy;
  ListNode* slow = dummy;

  // 快指针先走 n 步
  for (int i = 0; i < n; ++i) {
    fast = fast->next;
  }

  // 快慢同步，直到 fast 到达末尾
  // 此时 slow 指向待删节点的前驱
  while (fast->next != nullptr) {
    fast = fast->next;
    slow = slow->next;
  }

  ListNode* del = slow->next;
  slow->next = del->next;
  delete del;

  ListNode* newHead = dummy->next;
  delete dummy;
  return newHead;
}

}  // namespace

RemoveNthNodeFromEndOfListSolution::RemoveNthNodeFromEndOfListSolution() {
  setMetaInfo({.id = 19,
               .title = "Remove Nth Node From End of List",
               .url = "https://leetcode.com/problems/remove-nth-node-from-end-of-list/"});
  registerStrategy(
      {.name = "Two Pointers",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Linked List", "Two Pointers"}},
      removeNthFromEndImpl);
}

ListNode* RemoveNthNodeFromEndOfListSolution::removeNthFromEnd(ListNode* head,
                                                               int n) {
  return getSolution()(head, n);
}

}  // namespace problem_19
}  // namespace leetcode
