#include "leetcode/problems/intersection-of-two-linked-lists.h"

namespace leetcode {
namespace problem_160 {

static ListNode* getIntersectionNodeImpl(ListNode* headA, ListNode* headB) {
  ListNode* pA = headA;
  ListNode* pB = headB;
  while (pA != pB) {
    pA = pA ? pA->next : headB;
    pB = pB ? pB->next : headA;
  }
  return pA;
}

IntersectionOfTwoLinkedListsSolution::IntersectionOfTwoLinkedListsSolution() {
  setMetaInfo({.id = 160,
               .title = "Intersection of Two Linked Lists",
               .url = "https://leetcode.com/problems/intersection-of-two-linked-lists/"});
  registerStrategy(
      {.name = "TwoPointers",
       .expected = "Accepted",
       .time_complexity = "O(m+n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "Linked List", "Two Pointers"}},
      getIntersectionNodeImpl);
}

ListNode* IntersectionOfTwoLinkedListsSolution::getIntersectionNode(
    ListNode* headA, ListNode* headB) {
  return getSolution()(headA, headB);
}

}  // namespace problem_160
}  // namespace leetcode
