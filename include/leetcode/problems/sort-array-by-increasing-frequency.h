#include "leetcode/core.h"

namespace leetcode {
namespace problem_1636 {

using Func = std::function<vector<int>(vector<int>&)>;

class SortArrayByIncreasingFrequencySolution : public SolutionBase<Func> {
 public:
  //! 1636. Sort Array by Increasing Frequency
  //! https://leetcode.com/problems/sort-array-by-increasing-frequency/
  vector<int> frequencySort(vector<int>& nums);

  SortArrayByIncreasingFrequencySolution();
};

}  // namespace problem_1636
}  // namespace leetcode
