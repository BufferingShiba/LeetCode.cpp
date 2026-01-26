#include "leetcode/core.h"

namespace leetcode {
namespace problem_1200 {

using Func = std::function<vector<vector<int>>(vector<int>&)>;

class MinimumAbsoluteDifferenceSolution : public SolutionBase<Func> {
 public:
  //! 1200. Minimum Absolute Difference
  //! https://leetcode.com/problems/minimum-absolute-difference/
  vector<vector<int>> minimumAbsDifference(vector<int>& arr);

  MinimumAbsoluteDifferenceSolution();
};

}  // namespace problem_1200
}  // namespace leetcode