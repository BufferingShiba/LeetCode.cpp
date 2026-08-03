#include "leetcode/core.h"

namespace leetcode {
namespace problem_1786 {

using Func = std::function<int(int, vector<vector<int>>&)>;

class NumberOfRestrictedPathsFromFirstToLastNodeSolution : public SolutionBase<Func> {
 public:
  //! 1786. Number of Restricted Paths From First to Last Node
  //! https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/
  int countRestrictedPaths(int n, vector<vector<int>>& edges);

  NumberOfRestrictedPathsFromFirstToLastNodeSolution();
};

}  // namespace problem_1786
}  // namespace leetcode
