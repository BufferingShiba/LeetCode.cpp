#include "leetcode/problems/merge-k-sorted-lists.h"

namespace leetcode {
namespace problem_23 {

// 合并两个有序链表，返回新头节点
static ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
  ListNode dummy;
  ListNode* tail = &dummy;
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
  tail->next = a ? a : b;
  return dummy.next;
}

// 分治归并：迭代式两两合并
static ListNode* mergeKListsImpl(std::vector<ListNode*>& lists) {
  if (lists.empty()) return nullptr;

  int k = static_cast<int>(lists.size());
  for (int step = 1; step < k; step *= 2) {
    for (int i = 0; i + step < k; i += step * 2) {
      lists[i] = mergeTwoLists(lists[i], lists[i + step]);
    }
  }
  return lists[0];
}

MergeKSortedListsSolution::MergeKSortedListsSolution() {
  setMetaInfo({.id = 23,
               .title = "Merge k Sorted Lists",
               .url = "https://leetcode.com/problems/merge-k-sorted-lists/"});
  registerStrategy(
      {.name = "Divide and Conquer",
       .expected = "Accepted",
       .time_complexity = "O(N log k)",
       .space_complexity = "O(1)",
       .tags = {"Linked List", "Divide and Conquer", "Merge Sort"}},
      mergeKListsImpl);
}

ListNode* MergeKSortedListsSolution::mergeKLists(
    std::vector<ListNode*>& lists) {
  return getSolution()(lists);
}

}  // namespace problem_23
}  // namespace leetcode
