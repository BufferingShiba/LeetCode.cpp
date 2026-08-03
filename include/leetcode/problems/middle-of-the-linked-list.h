#ifndef LEETCODE_PROBLEMS_MIDDLE_OF_THE_LINKED_LIST_H__
#define LEETCODE_PROBLEMS_MIDDLE_OF_THE_LINKED_LIST_H__

#include <functional>
#include <string>

#include "leetcode/core.h"
#include "leetcode/utils/linked-list.h"

namespace leetcode::problem_876 {

using Func = std::function<leetcode::ListNode*(leetcode::ListNode*)>;

class MiddleOfTheLinkedListSolution
    : public SolutionBase<Func> {
 public:
  MiddleOfTheLinkedListSolution();

  leetcode::ListNode* middleNode(leetcode::ListNode* head);
};

}  // namespace leetcode::problem_876

#endif  // LEETCODE_PROBLEMS_MIDDLE_OF_THE_LINKED_LIST_H__
