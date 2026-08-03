
#include "leetcode/core.h"

namespace leetcode {
namespace problem_941 {

using Func = std::function<bool(vector<int>&)>;

class ValidMountainArraySolution : public SolutionBase<Func> {
 public:
  //! 941. Valid Mountain Array
  //! https://leetcode.com/problems/valid-mountain-array/
  bool validMountainArray(vector<int>& arr);

  ValidMountainArraySolution();
};

}  // namespace problem_941
}  // namespace leetcode
