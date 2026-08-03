#ifndef LEETCODE_PROBLEMS_REMOVE_DUPLICATES_FROM_SORTED_LIST_H__
#define LEETCODE_PROBLEMS_REMOVE_DUPLICATES_FROM_SORTED_LIST_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_83 {

using Func = std::function<ListNode*(ListNode*)>;

class RemoveDuplicatesFromSortedListSolution
    : public SolutionBase<Func> {
 public:
  ListNode* deleteDuplicates(ListNode* head);

  RemoveDuplicatesFromSortedListSolution();
};

}  // namespace problem_83
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_DUPLICATES_FROM_SORTED_LIST_H__
