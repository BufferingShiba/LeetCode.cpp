#include "leetcode/core.h"

namespace leetcode {
namespace problem_2196 {

using Func = std::function<TreeNode*(vector<vector<int>>&)>;

class CreateBinaryTreeFromDescriptionsSolution : public SolutionBase<Func> {
 public:
  //! 2196. Create Binary Tree From Descriptions
  //! https://leetcode.com/problems/create-binary-tree-from-descriptions/
  TreeNode* createBinaryTree(vector<vector<int>>& descriptions);

  CreateBinaryTreeFromDescriptionsSolution();
};

}  // namespace problem_2196
}  // namespace leetcode
