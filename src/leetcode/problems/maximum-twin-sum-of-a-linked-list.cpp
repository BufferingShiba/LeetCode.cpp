#include "leetcode/problems/maximum-twin-sum-of-a-linked-list.h"

#include <algorithm>

namespace leetcode {
namespace problem_2130 {

static int solution1(ListNode* head) {
  // 快慢指针找到链表中点（slow 指向后半部分起点）
  ListNode *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // 原地反转后半部分链表
  ListNode* prev = nullptr;
  while (slow) {
    ListNode* next = slow->next;
    slow->next = prev;
    prev = slow;
    slow = next;
  }

  // prev 是反转后的后半段头，依次与前半段配对取最大 twin sum
  ListNode* first = head;
  ListNode* second = prev;
  int ans = 0;
  while (second) {
    ans = std::max(ans, first->val + second->val);
    first = first->next;
    second = second->next;
  }
  return ans;
}

MaximumTwinSumOfALinkedListSolution::MaximumTwinSumOfALinkedListSolution() {
  setMetaInfo({
      .id = 2130,
      .title = "Maximum Twin Sum of a Linked List",
      .url = "https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list"
  });
  registerStrategy({.name = "Brute Force", .expected = "Accepted",
                    .time_complexity = "O(n)", .space_complexity = "O(1)",
                    .tags = {"Linked List", "Two Pointers"}},
                   solution1);
}

int MaximumTwinSumOfALinkedListSolution::pairSum(ListNode* head) {
  return getSolution()(head);
}

}  // namespace problem_2130
}  // namespace leetcode
