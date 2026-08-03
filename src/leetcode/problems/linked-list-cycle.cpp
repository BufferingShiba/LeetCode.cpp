#include "leetcode/problems/linked-list-cycle.h"

namespace leetcode {
namespace problem_141 {
namespace {

// Floyd's Tortoise and Hare: slow moves one step, fast moves two steps.
// If there is a cycle, they will eventually meet.
bool hasCycleImpl(ListNode *head) {
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return true;
    }
  }
  return false;
}

}  // namespace

LinkedListCycleSolution::LinkedListCycleSolution() {
  setMetaInfo({.id = 141,
               .title = "Linked List Cycle",
               .url = "https://leetcode.com/problems/linked-list-cycle/"});

  registerStrategy(
      {.name = "Floyd Cycle Detection (Two Pointers)",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Linked List", "Two Pointers", "Hash Table"}},
      hasCycleImpl);
}

bool LinkedListCycleSolution::hasCycle(ListNode *head) {
  return getSolution()(head);
}

}  // namespace problem_141
}  // namespace leetcode
