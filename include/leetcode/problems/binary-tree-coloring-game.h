#include "leetcode/core.h"

namespace leetcode {
namespace problem_1145 {

using Func = std::function<bool(TreeNode*, int, int)>;

class BinaryTreeColoringGameSolution : public SolutionBase<Func> {
 public:
  //! 1145. Binary Tree Coloring Game
  //! https://leetcode.com/problems/binary-tree-coloring-game/
  bool btreeGameWinningMove(TreeNode* root, int n, int x);

  BinaryTreeColoringGameSolution();
};

}  // namespace problem_1145
}  // namespace leetcode
