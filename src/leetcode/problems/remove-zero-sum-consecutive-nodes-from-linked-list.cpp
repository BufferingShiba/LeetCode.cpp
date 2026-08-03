#include "leetcode/problems/remove-zero-sum-consecutive-nodes-from-linked-list.h"

#include <unordered_map>

namespace leetcode {
namespace problem_1171 {

static ListNode* solution1(ListNode* head) {
  ListNode* dummy = new ListNode(0, head);
  std::unordered_map<int, ListNode*> seen;

  int prefix = 0;
  ListNode* cur = dummy;
  while (cur != nullptr) {
    prefix += cur->val;
    seen[prefix] = cur;
    cur = cur->next;
  }

  prefix = 0;
  cur = dummy;
  while (cur != nullptr) {
    prefix += cur->val;
    cur->next = seen[prefix]->next;
    cur = cur->next;
  }

  return dummy->next;
}

RemoveZeroSumConsecutiveNodesFromLinkedListSolution::RemoveZeroSumConsecutiveNodesFromLinkedListSolution() {
  setMetaInfo({
      .id = 1171,
      .title = "Remove Zero Sum Consecutive Nodes from Linked List",
      .url = "https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list"
  });
  registerStrategy({
      .name = "Two Pass with Prefix Sum Map",
      .expected = "Accepted",
      .time_complexity = "O(n)",
      .space_complexity = "O(n)",
      .tags = {"Hash Table", "Linked List"}
  }, solution1);
}

ListNode* RemoveZeroSumConsecutiveNodesFromLinkedListSolution::removeZeroSumSublists(ListNode* head) {
  return getSolution()(head);
}

}  // namespace problem_1171
}  // namespace leetcode
