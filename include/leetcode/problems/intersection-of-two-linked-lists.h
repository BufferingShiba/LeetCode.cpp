#ifndef LEETCODE_PROBLEMS_INTERSECTION_OF_TWO_LINKED_LISTS_H__
#define LEETCODE_PROBLEMS_INTERSECTION_OF_TWO_LINKED_LISTS_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_160 {

using Func = std::function<ListNode*(ListNode*, ListNode*)>;

class IntersectionOfTwoLinkedListsSolution : public SolutionBase<Func> {
 public:
  IntersectionOfTwoLinkedListsSolution();

  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
};

}  // namespace problem_160
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_INTERSECTION_OF_TWO_LINKED_LISTS_H__
