#include "leetcode/core.h"

namespace leetcode {
namespace problem_1458 {

using Func = std::function<int(vector<int>&, vector<int>&)>;

class MaxDotProductOfTwoSubsequencesSolution : public SolutionBase<Func> {
 public:
  //! 1458. Max Dot Product of Two Subsequences
  //! https://leetcode.com/problems/max-dot-product-of-two-subsequences/
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2);

  MaxDotProductOfTwoSubsequencesSolution();
};

}  // namespace problem_1458
}  // namespace leetcode