#include "leetcode/core.h"

namespace leetcode {
namespace problem_1748 {

using Func = std::function<int(vector<int>&)>;

class SumOfUniqueElementsSolution : public SolutionBase<Func> {
 public:
  //! 1748. Sum of Unique Elements
  //! https://leetcode.com/problems/sum-of-unique-elements/
  int sumOfUnique(vector<int>& nums);

  SumOfUniqueElementsSolution();
};

}  // namespace problem_1748
}  // namespace leetcode
