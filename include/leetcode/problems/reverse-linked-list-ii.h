#ifndef LEETCODE_PROBLEMS_REVERSE_LINKED_LIST_II_H_
#define LEETCODE_PROBLEMS_REVERSE_LINKED_LIST_II_H_

#include <functional>
#include "leetcode/core.h"

namespace leetcode::problem_92 {

using Func = std::function<leetcode::ListNode*(leetcode::ListNode*, int, int)>;

class ReverseLinkedListIiSolution : public SolutionBase<Func> {
 public:
  ReverseLinkedListIiSolution();

  leetcode::ListNode* reverseBetween(leetcode::ListNode* head, int left, int right);
};

}  // namespace leetcode::problem_92

#endif  // LEETCODE_PROBLEMS_REVERSE_LINKED_LIST_II_H_
