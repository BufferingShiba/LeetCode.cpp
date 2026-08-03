#include "leetcode/core.h"

namespace leetcode {
namespace problem_845 {

using Func = std::function<int(vector<int>&)>;

class LongestMountainInArraySolution : public SolutionBase<Func> {
 public:
  //! 845. Longest Mountain in Array
  //! https://leetcode.com/problems/longest-mountain-in-array/
  int longestMountain(vector<int>& arr);

  LongestMountainInArraySolution();
};

}  // namespace problem_845
}  // namespace leetcode
