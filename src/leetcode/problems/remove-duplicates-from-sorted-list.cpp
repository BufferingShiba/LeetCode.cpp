#include "leetcode/problems/remove-duplicates-from-sorted-list.h"

namespace leetcode {
namespace problem_83 {

namespace {

ListNode* deleteDuplicatesImpl(ListNode* head) {
  ListNode* cur = head;
  while (cur != nullptr && cur->next != nullptr) {
    if (cur->val == cur->next->val) {
      // 跳过重复节点，无需手动 delete（LeetCode 不要求，本地由测试管理内存）
      cur->next = cur->next->next;
    } else {
      cur = cur->next;
    }
  }
  return head;
}

}  // namespace

RemoveDuplicatesFromSortedListSolution::RemoveDuplicatesFromSortedListSolution() {
  setMetaInfo({.id = 83,
               .title = "Remove Duplicates from Sorted List",
               .url = "https://leetcode.com/problems/remove-duplicates-from-sorted-list/"});
  registerStrategy({.name = "Iterative",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Linked List"}},
                   deleteDuplicatesImpl);
}

ListNode* RemoveDuplicatesFromSortedListSolution::deleteDuplicates(
    ListNode* head) {
  return getSolution()(head);
}

}  // namespace problem_83
}  // namespace leetcode
