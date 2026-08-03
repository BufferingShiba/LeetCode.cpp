#ifndef LEETCODE_PROBLEMS_LINKED_LIST_COMPONENTS_H__
#define LEETCODE_PROBLEMS_LINKED_LIST_COMPONENTS_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_817 {

using Func = std::function<int(ListNode*, std::vector<int>&)>;

class LinkedListComponentsSolution : public SolutionBase<Func> {
 public:
  int numComponents(ListNode* head, std::vector<int>& nums);

  LinkedListComponentsSolution();
};

}  // namespace problem_817
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LINKED_LIST_COMPONENTS_H__
