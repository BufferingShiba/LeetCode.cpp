#include "leetcode/core.h"

namespace leetcode {
namespace problem_2859 {

using Func = std::function<int(vector<int>&, int)>;

class SumOfValuesAtIndicesWithKSetBitsSolution : public SolutionBase<Func> {
 public:
  //! 2859. Sum of Values at Indices With K Set Bits
  //! https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/
  int sumIndicesWithKSetBits(vector<int>& nums, int k);

  SumOfValuesAtIndicesWithKSetBitsSolution();
};

}  // namespace problem_2859
}  // namespace leetcode
