#include "leetcode/core.h"

namespace leetcode {
namespace problem_268 {

using Func = std::function<int(vector<int>&)>;

class MissingNumberSolution : public SolutionBase<Func> {
 public:
  //! 268. Missing Number
  //! https://leetcode.com/problems/missing-number/
  int missingNumber(vector<int>& nums);

  MissingNumberSolution();
};

}  // namespace problem_268
}  // namespace leetcode
