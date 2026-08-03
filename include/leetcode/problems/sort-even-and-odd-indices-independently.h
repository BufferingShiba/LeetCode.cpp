#include "leetcode/core.h"

namespace leetcode {
namespace problem_2164 {

using Func = std::function<vector<int>(vector<int>&)>;

class SortEvenAndOddIndicesIndependentlySolution : public SolutionBase<Func> {
 public:
  //! 2164. Sort Even and Odd Indices Independently
  //! https://leetcode.com/problems/sort-even-and-odd-indices-independently/
  vector<int> sortEvenOdd(vector<int>& nums);

  SortEvenAndOddIndicesIndependentlySolution();
};

}  // namespace problem_2164
}  // namespace leetcode
