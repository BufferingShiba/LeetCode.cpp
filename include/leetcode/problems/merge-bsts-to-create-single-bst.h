#ifndef LEETCODE_PROBLEMS_MERGE_BSTS_TO_CREATE_SINGLE_BST_H_
#define LEETCODE_PROBLEMS_MERGE_BSTS_TO_CREATE_SINGLE_BST_H_

#include "leetcode/core.h"
#include "leetcode/utils/tree.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_1932 {

using Func = std::function<TreeNode*(std::vector<TreeNode*>&)>;

class MergeBstsToCreateSingleBstSolution : public SolutionBase<Func> {
 public:
  MergeBstsToCreateSingleBstSolution();

  TreeNode* canMerge(std::vector<TreeNode*>& trees);
};

}  // namespace leetcode::problem_1932

#endif  // LEETCODE_PROBLEMS_MERGE_BSTS_TO_CREATE_SINGLE_BST_H_
