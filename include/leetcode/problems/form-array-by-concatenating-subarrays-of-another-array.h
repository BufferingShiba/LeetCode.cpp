#include "leetcode/core.h"

namespace leetcode {
namespace problem_1764 {

using Func = std::function<bool(vector<vector<int>>&, vector<int>&)>;

class FormArrayByConcatenatingSubarraysOfAnotherArraySolution : public SolutionBase<Func> {
 public:
  //! 1764. Form Array by Concatenating Subarrays of Another Array
  //! https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/
  bool canChoose(vector<vector<int>>& groups, vector<int>& nums);

  FormArrayByConcatenatingSubarraysOfAnotherArraySolution();
};

}  // namespace problem_1764
}  // namespace leetcode
