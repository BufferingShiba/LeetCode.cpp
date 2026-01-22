#include "leetcode/core.h"

namespace leetcode {
namespace problem_3507 {

using Func = std::function<int(vector<int>&)>;

class MinimumPairRemovalToSortArrayISolution : public SolutionBase<Func> {
 public:
  //! 3507. Minimum Pair Removal to Sort Array I
  //! https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/
  int minimumPairRemoval(vector<int>& nums);

  MinimumPairRemovalToSortArrayISolution();
};

}  // namespace problem_3507
}  // namespace leetcode
