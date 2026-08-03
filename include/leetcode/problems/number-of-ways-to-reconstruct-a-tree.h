#ifndef LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_RECONSTRUCT_A_TREE_H
#define LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_RECONSTRUCT_A_TREE_H

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1719 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class NumberOfWaysToReconstructATreeSolution : public SolutionBase<Func> {
 public:
  int checkWays(std::vector<std::vector<int>>& pairs);
  NumberOfWaysToReconstructATreeSolution();
};

}  // namespace problem_1719
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_RECONSTRUCT_A_TREE_H
