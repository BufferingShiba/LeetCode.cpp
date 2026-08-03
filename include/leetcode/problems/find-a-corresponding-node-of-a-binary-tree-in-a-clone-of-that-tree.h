#ifndef LEETCODE_PROBLEMS_FIND_A_CORRESPONDING_NODE_OF_A_BINARY_TREE_IN_A_CLONE_OF_THAT_TREE_H
#define LEETCODE_PROBLEMS_FIND_A_CORRESPONDING_NODE_OF_A_BINARY_TREE_IN_A_CLONE_OF_THAT_TREE_H

#include "leetcode/core.h"

namespace leetcode::problem_1379 {

using Func = std::function<TreeNode*(TreeNode*, TreeNode*, TreeNode*)>;

class FindACorrespondingNodeOfABinaryTreeInACloneOfThatTreeSolution
    : public SolutionBase<Func> {
 public:
  FindACorrespondingNodeOfABinaryTreeInACloneOfThatTreeSolution();
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target);
};

}  // namespace leetcode::problem_1379

#endif  // LEETCODE_PROBLEMS_FIND_A_CORRESPONDING_NODE_OF_A_BINARY_TREE_IN_A_CLONE_OF_THAT_TREE_H
