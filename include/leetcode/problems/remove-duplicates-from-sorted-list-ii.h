#include "leetcode/core.h"

namespace leetcode {
namespace problem_82 {

using Func = std::function<ListNode*(ListNode*)>;

class RemoveDuplicatesFromSortedListIiSolution : public SolutionBase<Func> {
 public:
  //! 82. Remove Duplicates from Sorted List II
  //! https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
  ListNode* deleteDuplicates(ListNode* head);

  RemoveDuplicatesFromSortedListIiSolution();
};

}  // namespace problem_82
}  // namespace leetcode
