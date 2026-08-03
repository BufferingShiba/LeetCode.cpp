#ifndef LEETCODE_PROBLEMS_REMOVE_LINKED_LIST_ELEMENTS_H__
#define LEETCODE_PROBLEMS_REMOVE_LINKED_LIST_ELEMENTS_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_203 {

using Func = std::function<ListNode*(ListNode*, int)>;

class RemoveLinkedListElementsSolution : public SolutionBase<Func> {
 public:
  RemoveLinkedListElementsSolution();

  ListNode* removeElements(ListNode* head, int val);
};

}  // namespace problem_203
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_LINKED_LIST_ELEMENTS_H__
