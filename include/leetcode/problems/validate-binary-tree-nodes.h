#include "leetcode/core.h"

namespace leetcode {
namespace problem_1361 {

using Func = std::function<bool(int, vector<int>&, vector<int>&)>;

class ValidateBinaryTreeNodesSolution : public SolutionBase<Func> {
 public:
  //! 1361. Validate Binary Tree Nodes
  //! https://leetcode.com/problems/validate-binary-tree-nodes/
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild);

  ValidateBinaryTreeNodesSolution();
};

}  // namespace problem_1361
}  // namespace leetcode
