#include "leetcode/core.h"

namespace leetcode {
namespace problem_179 {

using Func = std::function<string(vector<int>&)>;

class LargestNumberSolution : public SolutionBase<Func> {
 public:
  //! 179. Largest Number
  //! https://leetcode.com/problems/largest-number/
  string largestNumber(vector<int>& nums);

  LargestNumberSolution();
};

}  // namespace problem_179
}  // namespace leetcode
