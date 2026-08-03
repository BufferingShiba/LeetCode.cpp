#ifndef LEETCODE_PROBLEMS_ODD_EVEN_LINKED_LIST_H__
#define LEETCODE_PROBLEMS_ODD_EVEN_LINKED_LIST_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode {
namespace problem_328 {

using Func = std::function<leetcode::ListNode*(leetcode::ListNode*)>;

class OddEvenLinkedListSolution : public SolutionBase<Func> {
 public:
  OddEvenLinkedListSolution();

  leetcode::ListNode* oddEvenList(leetcode::ListNode* head);
};

}  // namespace problem_328
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ODD_EVEN_LINKED_LIST_H__
