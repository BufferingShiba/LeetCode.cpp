#ifndef LEETCODE_PROBLEMS_FIND_ELEMENTS_IN_A_CONTAMINATED_BINARY_TREE_H__
#define LEETCODE_PROBLEMS_FIND_ELEMENTS_IN_A_CONTAMINATED_BINARY_TREE_H__

#include <unordered_set>

#include "leetcode/utils/tree.h"

namespace leetcode::problem_1261 {

class FindElements {
 public:
  // Recover the contaminated binary tree and store all real node values.
  explicit FindElements(TreeNode* root);

  // Returns true if target exists in the recovered tree.
  bool find(int target);

 private:
  std::unordered_set<int> values_;
};

}  // namespace leetcode::problem_1261

#endif  // LEETCODE_PROBLEMS_FIND_ELEMENTS_IN_A_CONTAMINATED_BINARY_TREE_H__
