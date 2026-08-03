#include "leetcode/problems/reverse-nodes-in-k-group.h"

namespace leetcode {
namespace problem_25 {

namespace {

// Reverse the k nodes following `pre` in place.
// Pre:  pre -> a1 -> a2 -> ... -> ak -> rest
// Post: pre -> ak -> ... -> a1 -> rest
leetcode::ListNode* reverseKSmall(leetcode::ListNode* pre, int k) {
  leetcode::ListNode* cur = pre->next;  // a1, stays fixed as the running tail
  for (int i = 0; i < k - 1; ++i) {
    leetcode::ListNode* nxt = cur->next;  // next node to move to front
    cur->next = nxt->next;
    nxt->next = pre->next;
    pre->next = nxt;
  }
  return cur;  // a1, now the tail of the reversed group
}

leetcode::ListNode* reverseKGroupImpl(leetcode::ListNode* head, int k) {
  if (!head || k == 1) {
    return head;
  }
  leetcode::ListNode dummy(0, head);
  leetcode::ListNode* pre = &dummy;
  while (true) {
    // Check whether at least k nodes follow `pre`.
    leetcode::ListNode* probe = pre;
    int cnt = 0;
    while (cnt < k && probe->next) {
      probe = probe->next;
      ++cnt;
    }
    if (cnt < k) {
      break;  // not enough nodes left, keep them as is
    }
    pre = reverseKSmall(pre, k);
  }
  return dummy.next;
}

}  // namespace

ReverseNodesInKGroupSolution::ReverseNodesInKGroupSolution() {
  setMetaInfo({.id = 25,
               .title = "Reverse Nodes in k-Group",
               .url = "https://leetcode.com/problems/reverse-nodes-in-k-group/"});
  registerStrategy(
      {.name = "iterative-dummy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Linked List", "Recursion"}},
      reverseKGroupImpl);
}

leetcode::ListNode* ReverseNodesInKGroupSolution::reverseKGroup(
    leetcode::ListNode* head, int k) {
  return getSolution()(head, k);
}

}  // namespace problem_25
}  // namespace leetcode
