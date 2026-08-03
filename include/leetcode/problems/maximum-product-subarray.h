#include "leetcode/core.h"

namespace leetcode {
namespace problem_152 {

using Func = std::function<int(vector<int>&)>;

class MaximumProductSubarraySolution : public SolutionBase<Func> {
 public:
  //! 152. Maximum Product Subarray
  //! https://leetcode.com/problems/maximum-product-subarray/
  int maxProduct(vector<int>& nums);

  MaximumProductSubarraySolution();
};

}  // namespace problem_152
}  // namespace leetcode
