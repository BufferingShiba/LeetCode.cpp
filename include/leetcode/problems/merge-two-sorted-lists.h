#ifndef LEETCODE_PROBLEMS_MERGE_TWO_SORTED_LISTS_H__
#define LEETCODE_PROBLEMS_MERGE_TWO_SORTED_LISTS_H__

#include "leetcode/core.h"

namespace leetcode::problem_21 {

using Func = std::function<ListNode*(ListNode*, ListNode*)>;

class MergeTwoSortedListsSolution : public SolutionBase<Func> {
 public:
  MergeTwoSortedListsSolution();

  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
};

}  // namespace leetcode::problem_21

#endif
