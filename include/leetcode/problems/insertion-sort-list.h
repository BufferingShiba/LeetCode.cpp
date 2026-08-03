#ifndef LEETCODE_PROBLEMS_INSERTION_SORT_LIST_H_
#define LEETCODE_PROBLEMS_INSERTION_SORT_LIST_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_147 {

using Func = std::function<ListNode*(ListNode*)>;

class InsertionSortListSolution : public SolutionBase<Func> {
 public:
  InsertionSortListSolution();

  ListNode* insertionSortList(ListNode* head) {
    return getSolution()(head);
  }
};

}  // namespace problem_147
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_INSERTION_SORT_LIST_H_
