#include "leetcode/problems/insertion-sort-list.h"

namespace leetcode {
namespace problem_147 {

static ListNode* insertionSortListImpl(ListNode* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  ListNode dummy(0);
  ListNode* curr = head;

  while (curr != nullptr) {
    ListNode* next = curr->next;

    // Find the position in the sorted part where curr belongs
    ListNode* prev = &dummy;
    while (prev->next != nullptr && prev->next->val < curr->val) {
      prev = prev->next;
    }

    // Insert curr between prev and prev->next
    curr->next = prev->next;
    prev->next = curr;

    curr = next;
  }

  return dummy.next;
}

InsertionSortListSolution::InsertionSortListSolution() {
  setMetaInfo({.id = 147,
               .title = "Insertion Sort List",
               .url = "https://leetcode.com/problems/insertion-sort-list/"});

  registerStrategy(
      {.name = "Dummy Head Insertion",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(1)",
       .tags = {"Linked List", "Sorting"}},
      insertionSortListImpl);
}

}  // namespace problem_147
}  // namespace leetcode
