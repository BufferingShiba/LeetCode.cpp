#include "leetcode/core.h"

namespace leetcode {
namespace problem_2596 {

using Func = std::function<bool(vector<vector<int>>&)>;

class CheckKnightTourConfigurationSolution : public SolutionBase<Func> {
 public:
  //! 2596. Check Knight Tour Configuration
  //! https://leetcode.com/problems/check-knight-tour-configuration/
  bool checkValidGrid(vector<vector<int>>& grid);

  CheckKnightTourConfigurationSolution();
};

}  // namespace problem_2596
}  // namespace leetcode
