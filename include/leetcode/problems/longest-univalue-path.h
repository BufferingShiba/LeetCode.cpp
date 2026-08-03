#ifndef LEETCODE_PROBLEMS_LONGEST_UNIVALUE_PATH_H__
#define LEETCODE_PROBLEMS_LONGEST_UNIVALUE_PATH_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode::problem_687 {

using Func = std::function<int(TreeNode*)>;

class LongestUnivaluePathSolution : public SolutionBase<Func> {
 public:
  LongestUnivaluePathSolution();

  int longestUnivaluePath(TreeNode* root);
};

}  // namespace leetcode::problem_687

#endif  // LEETCODE_PROBLEMS_LONGEST_UNIVALUE_PATH_H__
