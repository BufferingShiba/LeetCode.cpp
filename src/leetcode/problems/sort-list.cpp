#include "leetcode/problems/sort-list.h"

#include "leetcode/utils/linked-list.h"

namespace leetcode {
namespace problem_148 {

namespace {

// Merge two sorted linked lists, appending after "tail". Returns the new tail.
ListNode* mergeLists(ListNode* a, ListNode* b, ListNode* tail) {
  while (a && b) {
    if (a->val <= b->val) {
      tail->next = a;
      a = a->next;
    } else {
      tail->next = b;
      b = b->next;
    }
    tail = tail->next;
  }
  tail->next = (a ? a : b);
  while (tail->next) tail = tail->next;
  return tail;
}

// Bottom-up merge sort. O(n log n) time, O(1) extra space.
ListNode* sortListImpl(ListNode* head) {
  if (!head) return nullptr;

  int n = 0;  // list length
  for (ListNode* cur = head; cur; cur = cur->next) ++n;

  ListNode dummy(0, head);

  for (int width = 1; width < n; width <<= 1) {
    ListNode* tail = &dummy;
    ListNode* cur = dummy.next;
    while (cur) {
      // Left run of size 'width'.
      ListNode* left = cur;
      ListNode* ltail = cur;
      for (int i = 1; i < width && ltail->next; ++i, ltail = ltail->next) {}

      // No right counterpart; the leftover run is already sorted.
      if (!ltail->next) {
        tail->next = left;
        break;
      }

      ListNode* right = ltail->next;
      ltail->next = nullptr;

      // Right run of size 'width'.
      ListNode* rtail = right;
      for (int i = 1; i < width && rtail->next; ++i, rtail = rtail->next) {}

      cur = rtail->next;   // start of the next pair
      rtail->next = nullptr;

      tail = mergeLists(left, right, tail);
    }
  }
  return dummy.next;
}

}  // namespace

SortListSolution::SortListSolution() {
  setMetaInfo({
      .id = 148,
      .title = "Sort List",
      .url = "https://leetcode.com/problems/sort-list/",
  });
  registerStrategy(
      {
          .name = "BottomUpMergeSort",
          .expected = "Accepted",
          .time_complexity = "O(n log n)",
          .space_complexity = "O(1)",
          .tags = {"Linked List", "Divide and Conquer", "Sorting", "Merge Sort"},
      },
      sortListImpl);
}

ListNode* SortListSolution::sortList(ListNode* head) {
  return getSolution()(head);
}

}  // namespace problem_148
}  // namespace leetcode
