#ifndef LEETCODE_PROBLEMS_MOST_FREQUENT_SUBTREE_SUM_H_
#define LEETCODE_PROBLEMS_MOST_FREQUENT_SUBTREE_SUM_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_508 {

using Func = std::function<std::vector<int>(TreeNode*)>;

class MostFrequentSubtreeSumSolution : public SolutionBase<Func> {
 public:
  MostFrequentSubtreeSumSolution();

  std::vector<int> findFrequentTreeSum(TreeNode* root);
};

}  // namespace leetcode::problem_508

#endif  // LEETCODE_PROBLEMS_MOST_FREQUENT_SUBTREE_SUM_H_
