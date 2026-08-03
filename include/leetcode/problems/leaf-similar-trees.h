#ifndef LEETCODE_PROBLEMS_LEAF_SIMILAR_TREES_H__
#define LEETCODE_PROBLEMS_LEAF_SIMILAR_TREES_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_872 {

using Func = std::function<bool(TreeNode*, TreeNode*)>;

class LeafSimilarTreesSolution : public SolutionBase<Func> {
 public:
  LeafSimilarTreesSolution();

  bool leafSimilar(TreeNode* root1, TreeNode* root2);
};

}  // namespace problem_872
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LEAF_SIMILAR_TREES_H__
