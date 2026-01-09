#include "leetcode/core.h"

namespace leetcode {
namespace problem_2 {

using Func = std::function<ListNode*(ListNode*, ListNode*)>;

class AddTwoNumbersSolution : public SolutionBase<Func> {
 public:
  //! 2. Add Two Numbers
  //! https://leetcode.com/problems/add-two-numbers/
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

  AddTwoNumbersSolution();
};

}  // namespace problem_2
}  // namespace leetcode