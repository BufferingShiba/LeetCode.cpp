#include "leetcode/core.h"

namespace leetcode {
namespace problem_78 {

using Func = std::function<std::vector<std::vector<int>>(const std::vector<int>&)>;

class SubsetsSolution : public SolutionBase<Func> {
 public:
  //! 78. Subsets
  //! https://leetcode.com/problems/subsets/
  std::vector<std::vector<int>> subsets(const std::vector<int>& nums);

  SubsetsSolution();
};

}  // namespace problem_78
}  // namespace leetcode
