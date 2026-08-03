#include "leetcode/core.h"

namespace leetcode {
namespace problem_2130 {

using Func = std::function<int(ListNode*)>;

class MaximumTwinSumOfALinkedListSolution : public SolutionBase<Func> {
 public:
  //! 2130. Maximum Twin Sum of a Linked List
  //! https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
  int pairSum(ListNode* head);

  MaximumTwinSumOfALinkedListSolution();
};

}  // namespace problem_2130
}  // namespace leetcode
