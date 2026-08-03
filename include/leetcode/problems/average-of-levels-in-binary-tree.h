#ifndef LEETCODE_PROBLEMS_AVERAGE_OF_LEVELS_IN_BINARY_TREE_H_
#define LEETCODE_PROBLEMS_AVERAGE_OF_LEVELS_IN_BINARY_TREE_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
struct TreeNode;
}  // namespace leetcode

namespace leetcode::problem_637 {

using Func = std::function<std::vector<double>(leetcode::TreeNode*)>;

class AverageOfLevelsInBinaryTreeSolution : public SolutionBase<Func> {
 public:
  std::vector<double> averageOfLevels(leetcode::TreeNode* root);

  AverageOfLevelsInBinaryTreeSolution();
};

}  // namespace leetcode::problem_637

#endif  // LEETCODE_PROBLEMS_AVERAGE_OF_LEVELS_IN_BINARY_TREE_H_
