#include "leetcode/problems/merge-two-sorted-lists.h"

namespace leetcode::problem_21 {

static ListNode* mergeTwoListsImpl(ListNode* list1, ListNode* list2) {
  ListNode dummy(0);
  ListNode* tail = &dummy;

  while (list1 != nullptr && list2 != nullptr) {
    if (list1->val <= list2->val) {
      tail->next = list1;
      list1 = list1->next;
    } else {
      tail->next = list2;
      list2 = list2->next;
    }
    tail = tail->next;
  }

  tail->next = (list1 != nullptr) ? list1 : list2;
  return dummy.next;
}

MergeTwoSortedListsSolution::MergeTwoSortedListsSolution() {
  setMetaInfo({.id = 21,
               .title = "Merge Two Sorted Lists",
               .url = "https://leetcode.com/problems/merge-two-sorted-lists/"});
  registerStrategy({.name = "iterative",
                     .expected = "Accepted",
                     .time_complexity = "O(m+n)",
                     .space_complexity = "O(1)",
                     .tags = {"Linked List", "Recursion"}},
                   mergeTwoListsImpl);
  setDefaultStrategy();
}

ListNode* MergeTwoSortedListsSolution::mergeTwoLists(ListNode* list1,
                                                     ListNode* list2) {
  return getSolution()(list1, list2);
}

}  // namespace leetcode::problem_21
