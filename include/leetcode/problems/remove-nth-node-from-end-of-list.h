#ifndef LEETCODE_PROBLEMS_REMOVE_NTH_NODE_FROM_END_OF_LIST_H__
#define LEETCODE_PROBLEMS_REMOVE_NTH_NODE_FROM_END_OF_LIST_H__

#include "leetcode/core.h"
#include "leetcode/utils/linked-list.h"

namespace leetcode {
namespace problem_19 {

using Func = std::function<ListNode*(ListNode*, int)>;

class RemoveNthNodeFromEndOfListSolution
    : public SolutionBase<Func> {
 public:
  RemoveNthNodeFromEndOfListSolution();

  ListNode* removeNthFromEnd(ListNode* head, int n);
};

}  // namespace problem_19
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_NTH_NODE_FROM_END_OF_LIST_H__
