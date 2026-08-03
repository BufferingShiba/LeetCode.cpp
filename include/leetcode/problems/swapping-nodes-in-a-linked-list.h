#ifndef LEETCODE_PROBLEMS_SWAPPING_NODES_IN_A_LINKED_LIST_H__
#define LEETCODE_PROBLEMS_SWAPPING_NODES_IN_A_LINKED_LIST_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"
#include "leetcode/utils/linked-list.h"

namespace leetcode {
namespace problem_1721 {

using Func = std::function<ListNode*(ListNode*, int)>;

class SwappingNodesInALinkedListSolution : public SolutionBase<Func> {
 public:
  SwappingNodesInALinkedListSolution();

  ListNode* swapNodes(ListNode* head, int k);
};

}  // namespace problem_1721
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SWAPPING_NODES_IN_A_LINKED_LIST_H__
