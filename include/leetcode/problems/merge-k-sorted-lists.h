#ifndef LEETCODE_PROBLEMS_MERGE_K_SORTED_LISTS_H_
#define LEETCODE_PROBLEMS_MERGE_K_SORTED_LISTS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_23 {

using Func = std::function<ListNode*(std::vector<ListNode*>&)>;

class MergeKSortedListsSolution : public SolutionBase<Func> {
 public:
  MergeKSortedListsSolution();

  ListNode* mergeKLists(std::vector<ListNode*>& lists);
};

}  // namespace problem_23
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MERGE_K_SORTED_LISTS_H_
