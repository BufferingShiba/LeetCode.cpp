#ifndef LEETCODE_PROBLEMS_SORT_LIST_H__
#define LEETCODE_PROBLEMS_SORT_LIST_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_148 {

using Func = std::function<ListNode*(ListNode*)>;

class SortListSolution : public SolutionBase<Func> {
 public:
  SortListSolution();

  ListNode* sortList(ListNode* head);
};

}  // namespace problem_148
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SORT_LIST_H__
