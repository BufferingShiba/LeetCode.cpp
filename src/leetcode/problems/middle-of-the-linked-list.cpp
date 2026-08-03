#include "leetcode/problems/middle-of-the-linked-list.h"

namespace leetcode::problem_876 {

// 快慢指针：快指针走两步，慢指针走一步，快指针到尾时慢指针恰好在中点。
static leetcode::ListNode* middleNodeImpl(leetcode::ListNode* head) {
  leetcode::ListNode* slow = head;
  leetcode::ListNode* fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

MiddleOfTheLinkedListSolution::MiddleOfTheLinkedListSolution() {
  this->setMetaInfo({.id = 876,
                     .title = "Middle of the Linked List",
                     .url =
                         "https://leetcode.com/problems/middle-of-the-linked-list/"});
  this->registerStrategy(
      {"Two Pointers", "Accepted", "O(n)", "O(1)", {"Linked List", "Two Pointers"}},
      middleNodeImpl);
}

leetcode::ListNode* MiddleOfTheLinkedListSolution::middleNode(
    leetcode::ListNode* head) {
  return this->getSolution()(head);
}

}  // namespace leetcode::problem_876
