#ifndef LEETCODE_PROBLEMS_DELETE_THE_MIDDLE_NODE_OF_A_LINKED_LIST_H__
#define LEETCODE_PROBLEMS_DELETE_THE_MIDDLE_NODE_OF_A_LINKED_LIST_H__

#include "leetcode/core.h"
#include "leetcode/utils/linked-list.h"

#include <functional>

namespace leetcode {
namespace problem_2095 {

using Func = std::function<leetcode::ListNode*(leetcode::ListNode*)>;

class DeleteTheMiddleNodeOfALinkedListSolution
    : public SolutionBase<Func> {
 public:
  DeleteTheMiddleNodeOfALinkedListSolution();

  leetcode::ListNode* deleteMiddle(leetcode::ListNode* head);
};

}  // namespace problem_2095
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DELETE_THE_MIDDLE_NODE_OF_A_LINKED_LIST_H__
