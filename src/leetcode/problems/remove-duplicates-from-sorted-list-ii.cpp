#include "leetcode/problems/remove-duplicates-from-sorted-list-ii.h"

namespace leetcode {
namespace problem_82 {

static ListNode* solution1(ListNode* head) {
  ListNode dummy(0, head);
  ListNode* prev = &dummy;
  ListNode* cur = head;
  while (cur != nullptr) {
    if (cur->next != nullptr && cur->next->val == cur->val) {
      int val = cur->val;
      while (cur != nullptr && cur->val == val) {
        ListNode* tmp = cur;
        cur = cur->next;
        delete tmp;
      }
      prev->next = cur;
    } else {
      prev = cur;
      cur = cur->next;
    }
  }
  return dummy.next;
}

RemoveDuplicatesFromSortedListIiSolution::RemoveDuplicatesFromSortedListIiSolution() {
  setMetaInfo({
      .id = 82,
      .title = "Remove Duplicates from Sorted List II",
      .url = "https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii"
  });
  registerStrategy({
      .name = "Brute Force",
      .time_complexity = "O(n)",
      .space_complexity = "O(1)",
      .tags = {"Linked List"},
  }, solution1);
}

ListNode* RemoveDuplicatesFromSortedListIiSolution::deleteDuplicates(ListNode* head) {
  return getSolution()(head);
}

}  // namespace problem_82
}  // namespace leetcode
