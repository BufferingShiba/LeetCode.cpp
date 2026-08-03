#ifndef LEETCODE_PROBLEMS_FLATTEN_A_MULTILEVEL_DOUBLY_LINKED_LIST_H__
#define LEETCODE_PROBLEMS_FLATTEN_A_MULTILEVEL_DOUBLY_LINKED_LIST_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode {
namespace problem_430 {

// Definition for a multilevel doubly linked list node.
struct Node {
  int val;
  Node* prev;
  Node* next;
  Node* child;

  Node() : val(0), prev(nullptr), next(nullptr), child(nullptr) {}
  Node(int _val)
      : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
  Node(int _val, Node* _prev, Node* _next, Node* _child)
      : val(_val), prev(_prev), next(_next), child(_child) {}
};

using FlattenFunc = std::function<Node*(Node*)>;

class FlattenAMultilevelDoublyLinkedListSolution
    : public SolutionBase<FlattenFunc> {
 public:
  FlattenAMultilevelDoublyLinkedListSolution();

  // Public method matching the problem signature.
  Node* flatten(Node* head);
};

}  // namespace problem_430
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FLATTEN_A_MULTILEVEL_DOUBLY_LINKED_LIST_H__
