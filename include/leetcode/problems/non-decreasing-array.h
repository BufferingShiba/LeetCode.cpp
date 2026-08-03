#include "leetcode/core.h"

namespace leetcode {
namespace problem_665 {

using Func = std::function<bool(vector<int>&)>;

class NonDecreasingArraySolution : public SolutionBase<Func> {
 public:
  //! 665. Non-decreasing Array
  //! https://leetcode.com/problems/non-decreasing-array/
  bool checkPossibility(vector<int>& nums);

  NonDecreasingArraySolution();
};

}  // namespace problem_665
}  // namespace leetcode
