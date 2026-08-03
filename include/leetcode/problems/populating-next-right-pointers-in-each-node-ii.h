#ifndef LEETCODE_PROBLEMS_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II_H__
#define LEETCODE_PROBLEMS_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode {
namespace problem_117 {

// Definition for a Node.
struct Node {
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  explicit Node(int _val)
      : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

using Func = std::function<Node*(Node*)>;

class PopulatingNextRightPointersInEachNodeIiSolution
    : public SolutionBase<Func> {
 public:
  PopulatingNextRightPointersInEachNodeIiSolution();

  Node* connect(Node* root);
};

}  // namespace problem_117
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_II_H__
