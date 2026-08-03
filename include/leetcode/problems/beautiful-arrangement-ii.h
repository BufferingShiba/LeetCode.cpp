
#include "leetcode/core.h"

namespace leetcode {
namespace problem_667 {

using Func = std::function<vector<int>(int, int)>;

class BeautifulArrangementIiSolution : public SolutionBase<Func> {
 public:
  //! 667. Beautiful Arrangement II
  //! https://leetcode.com/problems/beautiful-arrangement-ii/
  vector<int> constructArray(int n, int k);

  BeautifulArrangementIiSolution();
};

}  // namespace problem_667
}  // namespace leetcode
