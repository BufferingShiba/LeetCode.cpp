#include "leetcode/core.h"

namespace leetcode {
namespace problem_1171 {

using Func = std::function<ListNode*(ListNode*)>;

class RemoveZeroSumConsecutiveNodesFromLinkedListSolution : public SolutionBase<Func> {
 public:
  //! 1171. Remove Zero Sum Consecutive Nodes from Linked List
  //! https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
  ListNode* removeZeroSumSublists(ListNode* head);

  RemoveZeroSumConsecutiveNodesFromLinkedListSolution();
};

}  // namespace problem_1171
}  // namespace leetcode
