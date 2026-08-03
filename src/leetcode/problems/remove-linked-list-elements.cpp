#include "leetcode/problems/remove-linked-list-elements.h"

namespace leetcode {
namespace problem_203 {

namespace {

ListNode* removeElementsImpl(ListNode* head, int val) {
  ListNode dummy(0, head);
  ListNode* cur = &dummy;
  while (cur->next != nullptr) {
    if (cur->next->val == val) {
      ListNode* tmp = cur->next;
      cur->next = cur->next->next;
      delete tmp;
    } else {
      cur = cur->next;
    }
  }
  return dummy.next;
}

}  // namespace

RemoveLinkedListElementsSolution::RemoveLinkedListElementsSolution() {
  setMetaInfo({.id = 203,
               .title = "Remove Linked List Elements",
               .url = "https://leetcode.com/problems/remove-linked-list-elements/"});
  registerStrategy(
      {.name = "dummy-node-iteration",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Linked List"}},
      removeElementsImpl);
}

ListNode* RemoveLinkedListElementsSolution::removeElements(ListNode* head, int val) {
  return getSolution()(head, val);
}

}  // namespace problem_203
}  // namespace leetcode
