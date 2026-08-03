#include "leetcode/core.h"

namespace leetcode {
namespace problem_1722 {

using Func = std::function<int(vector<int>&, vector<int>&, vector<vector<int>>&)>;

class MinimizeHammingDistanceAfterSwapOperationsSolution : public SolutionBase<Func> {
 public:
  //! 1722. Minimize Hamming Distance After Swap Operations
  //! https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
  int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps);

  MinimizeHammingDistanceAfterSwapOperationsSolution();
};

}  // namespace problem_1722
}  // namespace leetcode
