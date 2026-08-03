#include "leetcode/problems/odd-even-linked-list.h"

namespace leetcode {
namespace problem_328 {
namespace {

// Results all odd-indexed nodes before even-indexed nodes, preserving
// relative order inside each group. Uses in-place pointer rearrangement in
// a single pass.
ListNode* oddEvenListImpl(ListNode* head) {
  if (head == nullptr) {
    return nullptr;
  }

  ListNode* odd = head;
  ListNode* even = head->next;
  ListNode* evenHead = even;

  while (even != nullptr && even->next != nullptr) {
    odd->next = even->next;
    odd = odd->next;
    even->next = odd->next;
    even = even->next;
  }

  odd->next = evenHead;
  return head;
}

}  // namespace

OddEvenLinkedListSolution::OddEvenLinkedListSolution() {
  setMetaInfo({.id = 328,
               .title = "Odd Even Linked List",
               .url = "https://leetcode.com/problems/odd-even-linked-list/"});
  registerStrategy({.name = "in-place-pointer-rearrange",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Linked List"}},
                   oddEvenListImpl);
}

ListNode* OddEvenLinkedListSolution::oddEvenList(ListNode* head) {
  return getSolution()(head);
}

}  // namespace problem_328
}  // namespace leetcode
