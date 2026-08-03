#ifndef LEETCODE_PROBLEMS_LINKED_LIST_CYCLE_H__
#define LEETCODE_PROBLEMS_LINKED_LIST_CYCLE_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode {
namespace problem_141 {

using Func = std::function<bool(ListNode *)>;

class LinkedListCycleSolution : public SolutionBase<Func> {
 public:
  LinkedListCycleSolution();

  bool hasCycle(ListNode *head);
};

}  // namespace problem_141
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LINKED_LIST_CYCLE_H__
